#pragma once

#include "nn/types.h"

namespace nn::nex {
class StorageUnit {
public:
    static bool AppendData(const StorageUnit*, StorageUnit*);
    static bool CopyData(const StorageUnit*, StorageUnit*);

    virtual ~StorageUnit();
    virtual size_t GetSize() const;
    virtual void Truncate();
    virtual size_t Read(u64, u64, u8*) const;
    virtual size_t Write(u64, u64, u8*);
    virtual bool Reserve(u64);
    virtual u32 GetReservedSize();
};
}  // namespace nn::nex
