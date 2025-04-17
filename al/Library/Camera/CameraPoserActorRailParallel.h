#pragma once

#include <math/seadVector.h>

#include "Library/Camera/CameraPoser.h"

namespace al {
class RailKeeper;

class CameraPoserActorRailParallel : public CameraPoser {
public:
    CameraPoserActorRailParallel(const char* name, const RailKeeper* railKeeper);

    void init() override;
    void loadParam(const ByamlIter& iter) override;
    void start(const CameraStartInfo& startInfo) override;
    void update() override;

public:
    const RailKeeper* mRailKeeper;
    sead::Vector3f mOffset;
    f32 mDistance;
    f32 mAngleDegreeH;
    f32 mAngleDegreeV;
    f32 mFollowRate;
};

static_assert(sizeof(CameraPoserActorRailParallel) == 0x168);

}  // namespace al
