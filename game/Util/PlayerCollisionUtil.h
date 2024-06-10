#pragma once

#include <basis/seadTypes.h>

namespace al {
class LiveActor;
}
class IUsePlayerHeightCheck;
class IUsePlayerCollision;

namespace rs {

f32 getGroundHeight(const IUsePlayerHeightCheck*);

bool isCollidedGround(const IUsePlayerCollision*);

bool isAutoRunOnGroundSkateCode(const al::LiveActor*, const IUsePlayerCollision*, float);

}  // namespace rs
