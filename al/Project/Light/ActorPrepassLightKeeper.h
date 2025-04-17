#pragma once

#include <container/seadPtrArray.h>

namespace sead {
class Color4f;
}  // namespace sead

namespace al {
class LiveActor;
class ParameterArray;
class ParameterBool;
class ParameterC4f;
class ParameterIo;
class ParameterObj;
class ParameterStringRef;
class PrePassLightBase;
class Resource;
struct ActorInitInfo;

class ActorPrePassLightKeeper {
public:
    class UserColor {
    public:
        UserColor();

    public:
        ParameterObj* mList;
        ParameterStringRef* mName;
        ParameterC4f* mColor;
    };

    static_assert(sizeof(UserColor) == 0x18);

    static bool isExistFile(const Resource*, const char*);

    ActorPrePassLightKeeper(LiveActor*);
    void init(const Resource*, const ActorInitInfo&, const char*);
    void initLightNum(s32);
    void initAfterPlacement();
    void appear(bool);
    void requestKill();
    void hideModel();
    void updateHideModel(bool);
    PrePassLightBase* getLightBase(const char*);
    PrePassLightBase* getLightBase(s32);
    sead::Color4f* findUserColor(const char*);

public:
    ParameterIo* mParameterIo;
    ParameterBool* mIsIgnoreHideModel;
    ParameterArray* mLightParameters;
    ParameterArray* mUserColorParameters;
    sead::PtrArray<PrePassLightBase*> mLights;
    sead::PtrArray<UserColor*> mUserColors;
    LiveActor* mLiveActor;
    bool mIsIgnorePrePassLightYaml;
};

static_assert(sizeof(ActorPrePassLightKeeper) == 0x50);
}  // namespace al
