#pragma once

#include <basis/seadTypes.h>

namespace al {
class LiveActor;
}  // namespace al

class DecalJointCtrl {
public:
    DecalJointCtrl(al::LiveActor* actor, s32 count);
    void calc();

public:
    u8 _0[0x28];
};

static_assert(sizeof(DecalJointCtrl) == 0x28);
