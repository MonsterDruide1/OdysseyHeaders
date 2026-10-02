#pragma once

#include <cstdarg>
#include <cstdint>

#include "Platform/Core/RootObject.h"
#include "Platform/Core/Time.h"

namespace nn::nex {

class OutputFormat : public RootObject {
public:
    OutputFormat();
    virtual ~OutputFormat() = default;

    virtual void StartString(char*, uint32_t);
    virtual uint32_t StartPrefixes(char*, uint32_t);
    static uint32_t AppendToString(char*, const char*, uint32_t);
    static void PreparePrefix(char*, uint32_t, const char*, ...);
    static uint32_t AddMessageImpl(char*, uint32_t, const char*, std::va_list);
    virtual void AddPrefixes(char*, uint32_t);
    virtual void EndPrefixes(char*, uint32_t);
    virtual void AddIndent(char*, uint32_t);
    virtual uint32_t AddMessage(char*, uint32_t, const char*, std::va_list);
    virtual void EndString(char*, uint32_t);
    void EnableNumberTraces(bool);
    void ShowProcessID(bool);
    void ShowThreadID(bool);
    void ShowLocalTime(bool);
    void ShowDateTime(bool);
    void ShowSystemThreadName(bool);
    void ShowLocalStationHandle(bool);
    void ShowSessionTime(bool);
    void ShowCurrentContext(bool);
    void ShowCID(bool);
    void ShowPID(bool);
    void AddPrefix(const char*);
    void IncreaseIndent(uint32_t);
    void DecreaseIndent(uint32_t);

public:
    uint32_t m_Indent = 0;
    uint32_t field_c = 0;
    bool field_10 = 0;
    bool field_11 = 0;
    bool field_12 = 0;
    bool field_13 = 0;
    bool m_bShowSessionTime = 0;
    bool field_15 = 0;
    bool field_16 = 0;
    bool m_bShowCurrentContext = 0;
    bool m_bShowCID = 0;
    bool m_bShowPID = 0;
    const char* m_Prefix;
    uint64_t m_ulTime;
};

}  // namespace nn::nex
