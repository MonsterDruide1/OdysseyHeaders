#pragma once

#include "MapObj/WorldMapParts.h"

class WorldMapRoute : public WorldMapParts {
public:
    WorldMapRoute* create(const char*, const char*, const al::ActorInitInfo&,
                          const sead::Matrix34<f32>*, f32);
    WorldMapRoute(const char*);

    void calcPose(const sead::Vector3<f32>&, const sead::Vector3<f32>&, const sead::Vector3<f32>&,
                  const sead::Vector3<f32>&, f32, bool, bool, bool, bool);
    void appear();
    void kill();
    void movement();
    void calcAnim();
    void openRoute(s32);
    void exeWait();
    void exeOpen();

public:
    sead::Vector3f mJointEnd;
    sead::Vector3f mJointMiddle;
    sead::Vector3f field_158;
};
