#pragma once

#include "nn/time.h"

namespace nn::nex {

class DateTime {
public:
    static DateTime& Never;
    static DateTime& Future;

    DateTime();
    DateTime(const DateTime&);
    DateTime(u16, u8, u8, u8, u8, u8);
    DateTime(const time::PosixTime&);
    DateTime& operator=(const DateTime&);
    DateTime(const time::CalendarTime&);

    DateTime(u64 time) { m_ulTime = time; }

    operator u64();
    operator u64() const;
    bool operator==(const DateTime&) const;
    bool operator!=(const DateTime&) const;
    bool operator<(const DateTime&) const;
    bool operator>(const DateTime&) const;
    bool operator<=(const DateTime&) const;
    bool operator>=(const DateTime&) const;
    DateTime operator-(const DateTime&) const;

    void FromUnixEpochTime(s64);
    s64 ToEpochTime() const;
    s32 GetYear() const;
    s32 GetMonth() const;
    s32 GetDay() const;
    s32 GetHour() const;
    s32 GetMinute() const;
    s32 GetSecond() const;
    bool IsValid() const;
    bool IsNever() const;
    void Trace(u64);
    time::PosixTime ToPosixTime() const;
    s64 ToUnixEpochTime() const;
    time::CalendarTime ToCalendarTime() const;
    static void GetSystemTime(DateTime&);
    static void GetLocalSystemTime(DateTime&);
    bool IsLeapYear(s32) const;
    s32 DateToDays(s32, s32, s32) const;
    void DaysToDate(s32);
    void FromCustomEpochTime(s64, s32);
    void FromEpochTime(s64);

public:
    u64 m_ulTime;
};

};  // namespace nn::nex
