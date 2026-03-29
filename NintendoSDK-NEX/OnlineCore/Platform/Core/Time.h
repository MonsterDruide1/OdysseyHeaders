#pragma once

#include <nn/types.h>

namespace nn::nex {
class TimeProvider;

class Time {
public:
    static u64 GetTime();
    static void Reset();
    static void RegisterTimeProvider(TimeProvider* provider);
    void Multiply(f32) const;
    void Divide(f32) const;
    void Scale(f32) const;
    static Time ConvertTimeoutToDeadline(u32 timeout);
    static u32 ConvertDeadlineToTimeout(Time deadline);

    u64 GetTimeVal() const { return m_Time; }

    operator u64() const { return m_Time; }

public:
    u64 m_Time = 0;
};
}  // namespace nn::nex
