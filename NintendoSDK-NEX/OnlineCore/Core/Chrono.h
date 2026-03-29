#pragma once

#include "Core/LocalClock.h"
#include "Platform/Core/RootObject.h"

namespace nn::nex {
class Chrono : public RootObject {
public:
    Chrono();
    virtual ~Chrono();

    void Reset();
    void Start();
    void Pause();
    void UpdateAccumulatedTime();
    void Elapsed() const;
    void Resume();
    void Check();
    void Stop();
    void GetState() const;

public:
    LocalClock m_LocalClock;
    u64 qword_18 = 0;
    s32 dword_20 = 0;
    s32 dword_24 = 2;
};
}  // namespace nn::nex
