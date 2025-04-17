#pragma once

#include "Library/Execute/IUseExecutor.h"
#include "Library/HostIO/HioNode.h"

namespace al {
class ExecuteDirector;
class PlacementId;
class StageSwitchAccesser;
class StageSwitchListener;
class StageSwitchWatcherHolder;
struct StageSwitchInfo;

class StageSwitchDirector : public HioNode, public IUseExecutor {
public:
    StageSwitchDirector(ExecuteDirector* executeDirector);

    s32 useSwitch(const StageSwitchAccesser* accesser);
    s32 findSwitchNoFromObjId(const PlacementId* placementId);
    void onSwitch(const StageSwitchAccesser* accesser);
    void offSwitch(const StageSwitchAccesser* accesser);
    bool isOnSwitch(const StageSwitchAccesser* accesser);
    void addListener(StageSwitchListener* listener, StageSwitchAccesser* accesser);
    void execute() override;

public:
    StageSwitchInfo* mSwitchInfos = nullptr;
    s32 mSwitchInfoCapacity = 128;
    s32 mSwitchInfoCount = 0;
    StageSwitchWatcherHolder* mSwitchWatcherHolder = nullptr;
};

static_assert(sizeof(StageSwitchDirector) == 0x20);

}  // namespace al
