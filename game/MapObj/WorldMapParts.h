#pragma once

#include <math/seadMatrix.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
class ActorInitInfo;
}  // namespace al

class WorldMapParts : public al::LiveActor {
public:
    WorldMapParts(const char*);

    void setWorldMtx(const sead::Matrix34f&);
    void updatePose();
    void control() override;

    virtual void setLocalMtx(const sead::Matrix34f&);

    static void initParts(WorldMapParts*, const char*, const al::ActorInitInfo&,
                          const sead::Matrix34f*, const sead::Matrix34f&, const char*);
    static WorldMapParts* create(const char*, const char*, const al::ActorInitInfo&,
                                 const sead::Matrix34f*, const sead::Matrix34f&, const char*);

public:
    const sead::Matrix34f* mWorldMtx = nullptr;
    sead::Matrix34f mLocalMtx = sead::Matrix34f::ident;
};
