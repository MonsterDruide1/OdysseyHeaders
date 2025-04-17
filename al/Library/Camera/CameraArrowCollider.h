#pragma once

#include <math/seadVector.h>

#include "Library/Collision/IUseCollision.h"
#include "Library/Nerve/NerveExecutor.h"

namespace sead {
class LookAtCamera;
}  // namespace sead

namespace al {
class CollisionDirector;
class CollisionParts;

class CameraArrowCollider : public NerveExecutor, public IUseCollision {
public:
    CameraArrowCollider(CollisionDirector* director);

    CollisionDirector* getCollisionDirector() const override;

    void start();
    void update(const sead::Vector3f& vec0, const sead::Vector3f& vec1, const sead::Vector3f& vec2);
    void pushBackCollisionParts(CollisionParts* parts);
    void makeLookAtCamera(sead::LookAtCamera* cam) const;

    void exeKeep();
    void exeShrink();

    bool isShrink() const;
    f32 getPushLength() const;
};
}  // namespace al
