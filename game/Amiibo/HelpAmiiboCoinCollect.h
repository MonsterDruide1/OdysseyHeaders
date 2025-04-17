#pragma once

#include <math/seadVector.h>

#include "Amiibo/HelpAmiiboExecutor.h"

namespace al {
class AreaObj;
class LiveActor;
}  // namespace al

class CoinCollect2D;
class CoinCollect;
class CoinCollectDummy;
class HelpAmiiboDirector;

class HelpAmiiboCoinCollect : public HelpAmiiboExecutor {
public:
    HelpAmiiboCoinCollect(HelpAmiiboDirector* director, al::LiveActor* amiiboActor);

    void initAfterPlacement(const al::ActorInitInfo& actorInitInfo) override;
    bool isTriggerTouch(const al::NfpInfo& nfpInfo) const override;
    bool isEnableUse() override;
    bool execute() override;
    void activate() override;
    HelpAmiiboType getType() const override;

    void deleteHintEffect();
    void appearEffect();
    void killEffect();
    bool isUseDummyModel(al::LiveActor* actor);
    void getDummyEffectEmitPos(sead::Vector3f* position, al::LiveActor* actor);

public:
    CoinCollect* mCoinCollect = nullptr;
    CoinCollect2D* mCoinCollect2D = nullptr;
    CoinCollectDummy* mCoinCollectDummy = nullptr;
    al::AreaObj* mStartInvalidateStageMapArea = nullptr;
};
