#pragma once

#include "Library/Layout/LayoutActor.h"

namespace al {
class LayoutInitInfo;
}

class GaugeAir : public al::LayoutActor {
public:
    GaugeAir(const char* name, const al::LayoutInitInfo& info);
    bool isWait() const;

    void start();
    void updateStateAnim();
    void endMax();
    void fastEnd();
    void setRate(f32 rate);

    void exeAppear();
    void exeWait();
    void exeEnd();
    void exeFastEnd();

public:
    bool mIsActive = false;
    bool mIsNotFull;
    f32 mRate = 1.0f;
};
