#pragma once

#include <cstdint>

namespace nn::nex {
class TimeProvider;

class Time {
public:
    static uint64_t GetTime();
    static void Reset();
    static void RegisterTimeProvider(TimeProvider* provider);
    void Multiply(float) const;
    void Divide(float) const;
    void Scale(float) const;
    static Time ConvertTimeoutToDeadline(uint32_t timeout);
    static uint32_t ConvertDeadlineToTimeout(Time deadline);

    uint64_t GetTimeVal() const { return m_Time; }

    operator uint64_t() const { return m_Time; }

public:
    uint64_t m_Time = 0;
};
}  // namespace nn::nex
