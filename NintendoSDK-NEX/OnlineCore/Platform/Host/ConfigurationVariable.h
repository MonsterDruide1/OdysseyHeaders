#pragma once

#include "Platform/Core/RootObject.h"

namespace nn::nex {
class String;

class ConfigurationVariable : public RootObject {
public:
    void GetName();
    ConfigurationVariable(char*, char*);
    void InitVariables();
    void SetName(char*);
    void SetValue(const char*);
    ~ConfigurationVariable();
    void GetSourceType();
    void Read();
    void ReadFromFile();
    void ReadFromEnvironment();
    void ReadFromRegistry();
    void ReadFromDefaultValue();
    void WriteToRegistry();
    void SetValue(String);
    void GetValue();
};
};  // namespace nn::nex
