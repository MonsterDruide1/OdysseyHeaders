#pragma once

#include "Platform/Core/RootObject.h"
#include "Platform/Core/Time.h"

namespace nn::nex {
class LocalClock : public RootObject {
public:
    static LocalClock* s_pInstance;

    LocalClock() { m_Time = Time::GetTime(); }

    virtual ~LocalClock();

    static void DeleteInstance();

public:
    u64 m_Time;
};
}  // namespace nn::nex
