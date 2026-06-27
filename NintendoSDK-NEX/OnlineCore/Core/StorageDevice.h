#pragma once

#include "Platform/Core/RootObject.h"

namespace nn::nex {
class String;
class StorageUnit;

class StorageDevice : public RootObject {
public:
    virtual StorageUnit* Create(const String&) = 0;
    virtual StorageUnit* Open(const String&) = 0;
    virtual bool Close(StorageUnit*) = 0;
    virtual bool Delete(const String&) = 0;
};
}  // namespace nn::nex
