#pragma once

#include <cstdint>

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
    uint64_t qword_18 = 0;
    int32_t dword_20 = 0;
    int32_t dword_24 = 2;
};
}  // namespace nn::nex
