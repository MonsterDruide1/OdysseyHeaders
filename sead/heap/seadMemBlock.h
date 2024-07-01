#pragma once
// from
// https://github.com/stupidestmodder/newergfx/blob/8393dcb3868699b4bb1cdac42f0e5c187a7f66e3/sead/include/heap/seadMemBlock.h

#include <basis/seadNew.h>
#include <basis/seadRawPrint.h>
#include <container/seadOffsetList.h>
#include <prim/seadMemUtil.h>
#include <prim/seadPtrUtil.h>

namespace sead
{

const size_t cPtrSize = sizeof(void*);
#define SEAD_PRINT(format, ...)                                                                    \
    do                                                                                             \
    {                                                                                              \
        if (false)                                                                                 \
            sead::system::Print(format, ##__VA_ARGS__);                                            \
    } while (0)

class MemBlock
{
public:
    MemBlock() : mListNode(), mHeapCheckTag(0), mOffset(0), mSize(0) {}

    u8* memory() const
    {
        return static_cast<u8*>(PtrUtil::addOffset(this, mOffset + sizeof(MemBlock)));
    }

    ListNode& getListNode() { return mListNode; }

    void setHeapCheckTag(u16 tag) { mHeapCheckTag = tag; }

    void setSize(size_t size)
    {
        SEAD_ASSERT(size % cPtrSize == 0);
        mSize = size;
    }

    void setOffset(u16 offset)
    {
        SEAD_ASSERT(offset % cPtrSize == 0);
        mOffset = offset;

        if (mOffset != 0)
        {
            intptr_t* offsetTail = reinterpret_cast<intptr_t*>(memory() - cPtrSize);
            SEAD_ASSERT(
                !PtrUtil::isInclude(offsetTail, this, PtrUtil::addOffset(this, sizeof(MemBlock))));
            *offsetTail = reinterpret_cast<intptr_t>(this) + 1;
        }
    }

    void fill(u8 val) { MemUtil::fill(memory(), val, mSize); }

    // TODO
    bool isInclude(const void*) const;

    friend class ExpHeap;

public:
    size_t getSize() const { return mSize; }

    size_t getSizeWithManage() const { return mOffset + sizeof(MemBlock) + mSize; }

    u32 getOffset() const { return mOffset; }

    bool isValid(const void* heapStart, size_t heapSize) const
    {
        if (mSize == 0)
            return false;

        const u8* start = reinterpret_cast<const u8*>(heapStart);
        const u8* block = reinterpret_cast<const u8*>(this);

        if (block < start || block + getSizeWithManage() > start + heapSize)
        {
            SEAD_PRINT("Invalid address: 0x%p\n", block);
            return false;
        }

        u8* next = reinterpret_cast<u8*>(mListNode.next());
        if (next < start || next + sizeof(MemBlock) > start + heapSize)
        {
            SEAD_PRINT("Invalid next address: 0x%p\n", next);
            return false;
        }

        u8* prev = reinterpret_cast<u8*>(mListNode.prev());
        if (prev < start || prev + sizeof(MemBlock) > start + heapSize)
        {
            SEAD_PRINT("Invalid prev address: 0x%p\n", prev);
            return false;
        }

        if (mListNode.prev()->next() != &mListNode || mListNode.next()->prev() != &mListNode)
        {
            SEAD_PRINT("Invalid bidirectional link\n");
            return false;
        }

        return true;
    }

    void dump() const
    {
        SEAD_PRINT("addr: 0x%p\n", this);
        SEAD_PRINT("memory: 0x%p\n", memory());
        SEAD_PRINT("size: 0x%p\n", getSize());
        SEAD_PRINT("prev: 0x%p\n", mListNode.prev());
        SEAD_PRINT("next: 0x%p\n", mListNode.next());
    }

    static MemBlock* FindManageArea(void* ptr)
    {
        MemBlock* block;

        uintptr_t offsetTail =
            *reinterpret_cast<uintptr_t*>(reinterpret_cast<intptr_t>(ptr) - cPtrSize);
        if ((offsetTail & 1) == 0)
        {
            block = reinterpret_cast<MemBlock*>(reinterpret_cast<intptr_t>(ptr) - sizeof(MemBlock));

#ifdef SEAD_DEBUG
            if (block->getOffset() != 0)
            {
                SEAD_PRINT("===================================\n");
                SEAD_PRINT("Invalid pointer: 0x%p\n", ptr);
                SEAD_PRINT("[ block (0x%p) ]\n", block);
                MemUtil::dumpMemoryBinary(block, 16 * 0, 16 * 2, true);
                SEAD_PRINT("\n");
                SEAD_PRINT("[ ptr (0x%p) ]\n", ptr);
                MemUtil::dumpMemoryBinary(ptr, 16 * 2, 16 * 2, true);
                SEAD_PRINT("===================================\n");

                SEAD_ASSERT_MSG(false, "Invalid pointer: 0x%p\n", ptr);
            }
#endif  // SEAD_DEBUG
        }
        else
        {
            block = reinterpret_cast<MemBlock*>(offsetTail - 1);
        }

        return block;
    }

public:
    ListNode mListNode;
    u16 mHeapCheckTag;
    u16 mOffset;
    size_t mSize;
};

using MemBlockList = OffsetList<MemBlock>;

}  // namespace sead
