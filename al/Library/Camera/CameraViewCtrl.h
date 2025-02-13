#pragma once

#include <basis/seadTypes.h>

namespace al {

class CameraSwitchRequester;

class PauseCameraCtrl {
public:
    PauseCameraCtrl(f32 v);

public:
    bool mIsPause;
    f32 _4;
};

class SceneCameraViewCtrl {
public:
    SceneCameraViewCtrl();

    CameraSwitchRequester* getSwitchRequester() { return mSwitchRequester; }

public:
    CameraSwitchRequester* mSwitchRequester = nullptr;
    const char* _8;
    void* _10;
};

class SceneCameraCtrl {
public:
    SceneCameraCtrl();
    void init(s32 viewNum);

    SceneCameraViewCtrl* getViewAt(s32 idx) { return &mViewArray[idx]; }

public:
    s32 mViewNumMax;
    SceneCameraViewCtrl* mViewArray;
    void* _10;
    void* _18;
};
}  // namespace al
