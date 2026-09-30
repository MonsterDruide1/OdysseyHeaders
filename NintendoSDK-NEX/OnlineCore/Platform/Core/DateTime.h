#pragma once

#include "nn/time.h"

namespace nn::nex {

class DateTime {
public:
    static DateTime& Never;
    static DateTime& Future;

    DateTime();
    DateTime(const DateTime&);
    DateTime(uint16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
    DateTime(const time::PosixTime&);
    DateTime& operator=(const DateTime&);
    DateTime(const time::CalendarTime&);

    DateTime(uint64_t time) { m_ulTime = time; }

    operator uint64_t();
    operator uint64_t() const;
    bool operator==(const DateTime&) const;
    bool operator!=(const DateTime&) const;
    bool operator<(const DateTime&) const;
    bool operator>(const DateTime&) const;
    bool operator<=(const DateTime&) const;
    bool operator>=(const DateTime&) const;
    DateTime operator-(const DateTime&) const;

    void FromUnixEpochTime(int64_t);
    int64_t ToEpochTime() const;
    int32_t GetYear() const;
    int32_t GetMonth() const;
    int32_t GetDay() const;
    int32_t GetHour() const;
    int32_t GetMinute() const;
    int32_t GetSecond() const;
    bool IsValid() const;
    bool IsNever() const;
    void Trace(uint64_t);
    time::PosixTime ToPosixTime() const;
    int64_t ToUnixEpochTime() const;
    time::CalendarTime ToCalendarTime() const;
    static void GetSystemTime(DateTime&);
    static void GetLocalSystemTime(DateTime&);
    bool IsLeapYear(int32_t) const;
    int32_t DateToDays(int32_t, int32_t, int32_t) const;
    void DaysToDate(int32_t);
    void FromCustomEpochTime(int64_t, int32_t);
    void FromEpochTime(int64_t);

public:
    uint64_t m_ulTime;
};

};  // namespace nn::nex
