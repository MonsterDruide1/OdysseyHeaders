#pragma once

#include <cstddef>
#include <cstdint>

namespace nn::nex {
class StorageUnit {
public:
    static bool AppendData(const StorageUnit*, StorageUnit*);
    static bool CopyData(const StorageUnit*, StorageUnit*);

    virtual ~StorageUnit();
    virtual size_t GetSize() const;
    virtual void Truncate();
    virtual size_t Read(uint64_t, uint64_t, uint8_t*) const;
    virtual size_t Write(uint64_t, uint64_t, uint8_t*);

    virtual bool Reserve(uint64_t) { return false; }

    virtual uint32_t GetReservedSize();
};
}  // namespace nn::nex
