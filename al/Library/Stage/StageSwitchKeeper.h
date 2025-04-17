#pragma once

namespace al {
class IUseName;
class PlacementInfo;
class StageSwitchAccesser;
class StageSwitchDirector;

struct StageSwitchAccesserList {
    StageSwitchAccesserList();
    StageSwitchAccesserList(const StageSwitchAccesser* accessers);

    const StageSwitchAccesser* accessers = nullptr;
    s32 accesserSize = 0;
    s32 accesserCapacity = 0;
};

class StageSwitchKeeper {
public:
    StageSwitchKeeper();
    void init(StageSwitchDirector* director, const PlacementInfo& placementInfo);
    StageSwitchAccesser* tryGetStageSwitchAccesser(const char* linkName) const;

    void setUseName(IUseName* useName) { mUseName = useName; }

public:
    StageSwitchAccesser* mAccessers = nullptr;
    s32 mAccesserSize = 0;
    IUseName* mUseName = nullptr;
};

}  // namespace al
