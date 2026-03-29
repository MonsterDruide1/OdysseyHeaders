#pragma once

#include "Core/StorageDevice.h"

namespace nn::nex {
class String;
class StorageUnit;

class FileStorageDevice : public StorageDevice {
public:
    FileStorageDevice();
    virtual ~FileStorageDevice();
    StorageUnit* Create(const String&);
    StorageUnit* Open(const String&);
    bool Close(StorageUnit*);
    bool Delete(const String&);
};
}  // namespace nn::nex
