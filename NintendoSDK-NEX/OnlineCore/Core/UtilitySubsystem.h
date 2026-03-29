#pragma once

#include "Platform/Core/RootObject.h"

namespace nn::nex {

class UtilitySubsystem : public RootObject {
public:
    static UtilitySubsystem* _Instance;

public:
    UtilitySubsystem();
    virtual ~UtilitySubsystem();
    static UtilitySubsystem* Instance();
};

}  // namespace nn::nex
