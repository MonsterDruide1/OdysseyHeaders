#pragma once

#include "Library/Camera/ActorCameraTarget.h"

namespace al {
class LiveActor;
}  // namespace al

class IUsePlayerCollision;

class PlayerColliderCameraTarget : public al::ActorCameraTarget {
public:
    PlayerColliderCameraTarget(const al::LiveActor*, const IUsePlayerCollision*);

    bool isCollideGround() const override;

public:
    const IUsePlayerCollision* mPlayerCollision;
};

static_assert(sizeof(PlayerColliderCameraTarget) == 0x30);
