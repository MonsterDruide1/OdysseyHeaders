#pragma once

namespace al {
class LiveActor;
struct ActorInitInfo;

class SubActorLodExecutor {
public:
    SubActorLodExecutor(LiveActor* actor, const ActorInitInfo& info, s32 subActorInfoIndex);

    void control();
    LiveActor* getLodSubActor();

public:
    enum class LodAction : s32 { None, HideActor, KillSubActor };

    LiveActor* mActor;
    LodAction mLodAction = LodAction::None;
    s32 mSubActorInfoIndex;
};

static_assert(sizeof(SubActorLodExecutor) == 0x10);
}  // namespace al
