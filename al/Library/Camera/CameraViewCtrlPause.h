#pragma once

#include <basis/seadTypes.h>

namespace al {

class PauseCameraCtrl {
public:
    PauseCameraCtrl(f32 v);

    void startCameraPause() { mIsCameraPause = true; }

    void endCameraPause() { mIsCameraPause = false; }

public:
    bool mIsCameraPause = false;
    f32 _4;
};

static_assert(sizeof(PauseCameraCtrl) == 0x8);

}  // namespace al
