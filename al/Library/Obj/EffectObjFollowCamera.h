#pragma once

#include <math/seadMatrix.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
class EffectObjFollowCamera : public LiveActor {
public:
    EffectObjFollowCamera(const char* name);

    void init(const ActorInitInfo& info) override;
    void startAppear();
    void startDisappear();
    void control() override;
    void exeWait();
    void exeDisappear();

public:
    sead::Matrix34f mBaseMtx = sead::Matrix34f::ident;
};

static_assert(sizeof(EffectObjFollowCamera) == 0x138);
}  // namespace al
