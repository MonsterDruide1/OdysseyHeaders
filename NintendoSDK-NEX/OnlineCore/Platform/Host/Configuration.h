#pragma once

#include <vector>
#include "Platform/Core/MemAllocator.h"
#include "Platform/Core/RootObject.h"

namespace nn::nex {

class ConfigurationVariable;

class Configuration : public RootObject {
public:
    Configuration();
    virtual ~Configuration();

    void CreateVariable(ConfigurationVariable*);
    void FindVariable(char*);
    void GetVariablesNumber();
    void GetVariable(uint32_t);

public:
    std::vector<ConfigurationVariable*, MemAllocator<ConfigurationVariable*>> m_vVariables;
};

}  // namespace nn::nex
