#pragma once

#include <cstdarg>
#include <cstdint>

#include "Platform/Core/RootObject.h"

namespace nn::nex {
class OutputFormat;
class LogDevice;
class LogFilter;

class Log : public RootObject {
public:
    Log();

    virtual ~Log();
    virtual void Output(const char*, ...);
    virtual void OutputString(const char*, ...);

    virtual void AddCustomPrefix(char*, int32_t, void*) {}

    void OutputImpl(const char*, std::va_list, void*);
    void PrepareOutput(char*, uint32_t, void*);
    void SetOutputFormat(OutputFormat*);
    void SetLogDevice(LogDevice*, bool);
    LogDevice* GetLogDevice();
    void SetLogFilter(LogFilter*);
    LogFilter* GetLogFilter();
    OutputFormat* GetOutputFormat();

public:
    LogDevice* m_LogDevice;
    OutputFormat* m_OutputFormat;
    LogFilter* m_LogFilter;
};
}  // namespace nn::nex
