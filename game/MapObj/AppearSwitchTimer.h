#pragma once

#include "Library/Nerve/NerveExecutor.h"

namespace al {
class IUseAudioKeeper;
class IUseCamera;
class IUseStageSwitch;
class LiveActor;
struct ActorInitInfo;
}  // namespace al

class AppearSwitchTimer : public al::NerveExecutor {
public:
    AppearSwitchTimer();
    void init(const al::ActorInitInfo&, const al::IUseAudioKeeper*, al::IUseStageSwitch*,
              al::IUseCamera*, al::LiveActor*);
    void onSwitch();
    bool isSwitchOn();
    void offSwitch();
    bool isDemoPlaying();
    void exeWaitAppearDemoStart();
    void exeWaitAppearDemoCameraInterpoling();
    void exeAppearDemo();
    void procAppearDitherAnim(s32);
    void exeOnWait();
    s32 getLastFrame();
    void exeOnWaitBlink();
    void exeOffWait();

public:
    void* filler[12];
};
