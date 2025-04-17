#pragma once

namespace al {
class StageResourceList;

class StageResourceKeeper {
public:
    StageResourceKeeper();

    void initAndLoadResource(const char* stageName, s32 scenarioNo);

public:
    StageResourceList** mResourceList = nullptr;
    const char* mStageName = nullptr;
    s32 mScenarioNo = -1;
};

}  // namespace al
