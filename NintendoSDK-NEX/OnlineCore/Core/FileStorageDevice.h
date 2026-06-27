#pragma once

#include "Core/StorageDevice.h"

namespace nn::nex {
class String;
class StorageUnit;

class FileStorageDevice : public StorageDevice {
public:
    FileStorageDevice();
    ~FileStorageDevice() override;

    StorageUnit* Create(const String&) override;
    StorageUnit* Open(const String&) override;
    bool Close(StorageUnit*) override;
    bool Delete(const String&) override;
};
}  // namespace nn::nex
