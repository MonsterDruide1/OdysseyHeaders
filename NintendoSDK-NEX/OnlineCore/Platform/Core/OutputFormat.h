#pragma once

#include <cstdarg>
#include "Platform/Core/RootObject.h"
#include "Platform/Core/Time.h"

namespace nn::nex {

class OutputFormat : public RootObject {
public:
    OutputFormat();
    virtual ~OutputFormat();

    virtual void StartString(char*, u32);
    virtual u32 StartPrefixes(char*, u32);
    static u32 AppendToString(char*, const char*, u32);
    static void PreparePrefix(char*, u32, const char*, ...);
    static u32 AddMessageImpl(char*, u32, const char*, std::va_list);
    virtual void AddPrefixes(char*, u32);
    virtual void EndPrefixes(char*, u32);
    virtual void AddIndent(char*, u32);
    virtual u32 AddMessage(char*, u32, const char*, std::va_list);
    virtual void EndString(char*, u32);
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
    void IncreaseIndent(u32);
    void DecreaseIndent(u32);

public:
    u32 m_Indent = 0;
    u32 field_c = 0;
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
    u64 m_ulTime;
};

}  // namespace nn::nex
