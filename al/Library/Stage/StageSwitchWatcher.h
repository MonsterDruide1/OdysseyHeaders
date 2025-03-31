#pragma once

namespace al {
class StageSwitchAccesser;
class StageSwitchListener;

class StageSwitchWatcher {
public:
    StageSwitchWatcher(StageSwitchListener* switchListener, StageSwitchAccesser* switchAccesser);
    void update();

public:
    StageSwitchListener* mSwitchListener;
    StageSwitchAccesser* mSwitchAccesser;
    bool mIsSwitchOn = false;
};

}  // namespace al
