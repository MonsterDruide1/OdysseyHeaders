#pragma once

namespace al {
class LayoutActor;

class LayoutPartsActorKeeper {
public:
    LayoutPartsActorKeeper(s32 maxActors);

    void resisterPartsActor(LayoutActor* actor);
    void appear();
    void kill();
    void update();
    void calcAnim(bool recursive);

public:
    LayoutActor** mPartsActors = nullptr;
    s32 mNumActors = 0;
    s32 mMaxActors = 0;
};
}  // namespace al
