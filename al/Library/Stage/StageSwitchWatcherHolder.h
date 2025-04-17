#pragma once

namespace al {
class StageSwitchWatcher;

class StageSwitchWatcherHolder {
public:
    StageSwitchWatcherHolder(s32 capacity);

    void add(StageSwitchWatcher* watcher);
    void movement();

public:
    StageSwitchWatcher** mSwitchWatchers = nullptr;
    s32 mSwitchWatcherCount = 0;
    s32 mSwitchWatcherCapacity;
};
}  // namespace al
