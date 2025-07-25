#pragma once

#include <prim/seadSafeString.h>

namespace al {

class BgmChangeableParams {
public:
    BgmChangeableParams();

    void operator=(const BgmChangeableParams& value);

    void calcPitch(f32 value);

public:
    f32 mVolume = 1.0;
    f32 mPitch = 0;
    f32 mLpfFreq = 0;
    f32 mBiquadFilter = 0;
    f32 mVar = 0;
    f32 mAuxBusSend = 0;
    f32 mTrackVolume0 = 1.0;
    f32 mTrackVolume1 = 0;
    f32 mTrackVolume2 = 0;
    f32 mTrackVolume3 = 0;
    f32 mTrackVolume4 = 0;
    f32 mTrackVolume5 = 0;
};

struct BgmUserInfo;
class ByamlIter;
class SafeString;
template <typename T>
class AudioInfoListWithParts;
class BgmActionInfo;
class BgmSourceInfo;

struct BgmUserInfo {
    static BgmUserInfo* createInfo(const ByamlIter&, const sead::SafeString&);

    BgmUserInfo();

    static s32 compareInfo(const BgmUserInfo* info_1, const BgmUserInfo* info_2);
    static s32 compareInfoByKey(const BgmUserInfo* info, const char* string);

    const char* name = nullptr;
    AudioInfoListWithParts<BgmActionInfo>* bgmActionInfoList = nullptr;
    AudioInfoListWithParts<BgmSourceInfo>* bgmSourceInfoList = nullptr;
};
}  // namespace al
