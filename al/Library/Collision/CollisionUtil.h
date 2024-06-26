#pragma once

#include <math/seadVector.h>

namespace al {
class HitInfo;
class IUseCollision;
class ArrowHitInfo;
class CollisionPartsFilterBase;
class TriangleFilterBase;

}  // namespace al

namespace alCollisionUtil {

const sead::Vector3f& getCollisionHitPos(const al::HitInfo*);
const sead::Vector3f& getCollisionHitNormal(const al::HitInfo*);

bool getLastPolyOnArrow(const al::IUseCollision*, const al::ArrowHitInfo**, const sead::Vector3f&,
                        const sead::Vector3f&, const al::CollisionPartsFilterBase*,
                        const al::TriangleFilterBase*);
s32 checkStrikeArrow(const al::IUseCollision*, const sead::Vector3f&, const sead::Vector3f&,
                      const al::CollisionPartsFilterBase*, const al::TriangleFilterBase*);

}  // namespace alCollisionUtil
