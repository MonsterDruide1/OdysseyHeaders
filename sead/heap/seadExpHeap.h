#pragma once

#include "heap/seadHeap.h"
#include "heap/seadMemBlock.h"
#include "prim/seadSizedEnum.h"

namespace sead
{
class ExpHeap : public Heap
{
    SEAD_RTTI_OVERRIDE(ExpHeap, Heap)
public:
    enum class AllocMode
    {
        FirstFit = 0,
        BestFit = 1,
    };

    enum class FindFreeBlockMode
    {
        Auto = 0,
        FromFreeList = 1,
        ByIteratingMemBlock = 2,
    };

    enum class FindMode
    {
        eFirstFit = 0,
        eBestFit,
        eMaxSize
    };

    static ExpHeap* create(size_t size, const SafeString& name, Heap* parent, s32 alignment,
                           HeapDirection direction, bool);
    static ExpHeap* create(void* address, size_t size, const SafeString& name, bool);
    static ExpHeap* create(void* address, size_t size, const SafeString& name, Heap* parent, bool);

    static ExpHeap* tryCreate(size_t size, const SafeString& name, Heap* parent, s32 alignment,
                              HeapDirection direction, bool);
    static ExpHeap* tryCreate(void* address, size_t size, const SafeString& name, bool);
    static ExpHeap* tryCreate(void* address, size_t size, const SafeString& name, Heap* parent, bool);

    static size_t getManagementAreaSize(s32);

    void destroy() override;
    size_t adjust() override;
    void* tryAlloc(size_t size, s32 alignment) override;
    void free(void* ptr) override;
    void* resizeFront(void* p_void, size_t size) override;
    void* resizeBack(void* p_void, size_t size) override;
    void* tryRealloc(void* ptr, size_t size, s32 alignment) override;
    void freeAll() override;
    const void* getStartAddress() const override;
    const void* getEndAddress() const override;
    size_t getSize() const override;
    size_t getFreeSize() const override;
    size_t getMaxAllocatableSize(int alignment) const override;
    bool isInclude(const void* p_void) const override;
    bool isEmpty() const override;
    bool isFreeable() const override;
    bool isResizable() const override;
    bool isAdjustable() const override;
    void dump() const override;
    void dumpYAML(WriteStream& stream, int i) const override;
    void genInformation_(hostio::Context* context) override;

    virtual s32 destroyAndGetAllocatableSize(s32);
    virtual void setFindFreeBlockMode(FindFreeBlockMode mode);

    AllocMode getAllocMode() const { return mAllocMode; }
    void setAllocMode(AllocMode mode) { mAllocMode = mode; }

    // XXX: this isn't const-correct...
    size_t getAllocatedSize(void* object);

    void dumpFreeList() const;
    void dumpUseList() const;

    void checkFreeList() const;
    bool tryCheckFreeList() const;
    void checkUseList() const;
    bool tryCheckUseList() const;

public:
    ExpHeap(const SafeString& name, Heap* parent, void* address, size_t size,
            HeapDirection direction, bool);
    ~ExpHeap() override;

    static void doCreate(ExpHeap*, Heap*);

    static void createMaxSizeFreeMemBlock_(ExpHeap*);
    MemBlock* findFreeMemBlockFromHead_(size_t, FindMode) const;
    MemBlock* findFreeMemBlockFromHead_(size_t, s32, FindMode) const;
    MemBlock* findFreeMemBlockFromTail_(size_t, FindMode) const;
    MemBlock* findFreeMemBlockFromTail_(size_t, s32, FindMode) const;
    MemBlock* findLastMemBlockIfFree_();
    MemBlock* findFirstMemBlockIfFree_();

    void* realloc_(void* ptr, u8* oldMem, size_t copySize, size_t newSize, s32 alignment);

    void pushToUseList_(MemBlock*);
    void pushToFreeList_(MemBlock*);

    size_t adjustBack_();
    size_t adjustFront_();

    MemBlock* allocFromHead_(size_t);
    MemBlock* allocFromHead_(size_t, s32);
    MemBlock* allocFromTail_(size_t);
    MemBlock* allocFromTail_(size_t, s32);

    static s32 compareMemBlockAddr_(const MemBlock*, const MemBlock*);

    AllocMode mAllocMode;
    SizedEnum<FindFreeBlockMode, u8> mFindFreeBlockMode;
    MemBlockList mFreeList;
    MemBlockList mUseList;

    static const s32 cDefaultAlignment = 16;//alignof(void*);
    static const s32 cMinAlignment = 16;//cDefaultAlignment;
};
}  // namespace sead
