#pragma once

#include <prim/seadSafeString.h>

namespace al {
class ActorInitInfo;
class LiveActor;
class Scene;
class IUseSceneObjHolder;
}  // namespace al
class BarrierField;
class OceanWaveActor;
class ShineTowerRocket;
class RiseMapPartsHolder;
class Shine;
class IUseDemoSkip;
class CaptionInfoHolder;
class CinemaCaption;
class DemoHackFirstDirector;

namespace rs {
al::LiveActor* createDemoPeachWedding(const al::ActorInitInfo&);
al::LiveActor* createDemoCapManHeroine(const al::ActorInitInfo&);
bool isRandomActionDemoChangeWorld(const al::LiveActor*, const char*);
bool tryGetDemoChangeWorldRandomActionName(sead::BufferedSafeString*, s32*, const al::LiveActor*,
                                           const char*);

bool requestStartDemoNormal(al::LiveActor*, bool);
void addDemoActor(al::LiveActor*, bool);
void requestEndDemoNormal(const al::LiveActor*);
bool requestStartDemoNormal(const al::Scene*);
void requestEndDemoNormal(const al::Scene*);
bool requestStartDemoNormalWithCinemaFrame(al::LiveActor*);
void requestEndDemoNormalWithCinemaFrame(const al::LiveActor*);
bool requestStartDemoWithPlayer(al::LiveActor*, bool);
void requestEndDemoWithPlayer(const al::LiveActor*);
bool requestStartDemoWithPlayer(const al::Scene*);
void requestEndDemoWithPlayer(const al::Scene*);
bool requestStartDemoWithPlayerCinemaFrame(al::LiveActor*, bool);
void requestEndDemoWithPlayerCinemaFrame(const al::LiveActor*);
bool requestStartDemoWithPlayerKeepCarry(al::LiveActor*, bool);
void requestEndDemoWithPlayerKeepCarry(const al::LiveActor*);
bool requestStartDemoWithPlayerUseCoin(al::LiveActor*, bool);
void requestEndDemoWithPlayerUseCoin(const al::LiveActor*);
bool requestStartDemoWithPlayerKeepBindTalk(al::LiveActor*, bool);
void requestEndDemoWithPlayerKeepBindTalk(const al::LiveActor*);
bool requestStartDemoKeepHackTalk(al::LiveActor*, bool);
void requestEndDemoKeepHackTalk(const al::LiveActor*);
bool requestStartDemoWithPlayerCinemaFrameTalk(al::LiveActor*, bool);
void requestEndDemoWithPlayerCinemaFrameTalk(const al::LiveActor*);
bool requestStartDemoWithPlayerKeepCarryTalk(al::LiveActor*, bool);
void requestEndDemoWithPlayerKeepCarryTalk(const al::LiveActor*);
bool requestStartDemoWithPlayerUseCoinTalk(al::LiveActor*, bool);
void requestEndDemoWithPlayerUseCoinTalk(const al::LiveActor*);
bool requestStartDemoNormalTalk(al::LiveActor*, bool);
void requestEndDemoNormalTalk(const al::LiveActor*);
bool requestStartDemoWarpToCheckpoint(const al::Scene*);
bool requestStartDemoBossBattleStart(al::LiveActor*);
void requestEndDemoBossBattleStart(const al::LiveActor*);
bool requestStartDemoBossBattleEnd(al::LiveActor*);
void requestEndDemoBossBattleEnd(const al::LiveActor*);
bool requestStartDemoShineGet(Shine*);
bool requestStartDemoAchievementShineGet(al::Scene*);
void endDemoShineGet(al::Scene*);
void requestEndDemoShineGet(const al::Scene*);
void requestEndDemoShineGet(const al::LiveActor*);
bool requestStartDemoShineDotGet(Shine*);
void requestEndDemoShineDotGet(const al::Scene*);
bool requestStartDemoShineMainGet(Shine*);
void setDemoInfoDemoName(const al::LiveActor*, const char*);
void requestEndDemoShineMainGet(const al::LiveActor*);
void requestEndDemoShineMainGet(const al::Scene*);
bool requestStartDemoShineGrandGet(Shine*);
void requestEndDemoShineGrandGet(const al::LiveActor*);
void requestEndDemoShineGrandGet(const al::Scene*);
bool requestStartDemoShineAppear(al::LiveActor*);
void requestEndDemoShineAppear(const al::LiveActor*);
bool requestStartDemoShineAppear(const al::Scene*);
void requestEndDemoShineAppear(const al::Scene*);
bool requestStartDemoWarp(al::LiveActor*);
bool requestStartDemoWarp(const al::Scene*);
void requestEndDemoWarp(const al::LiveActor*);
void requestEndDemoWarp(const al::Scene*);
bool requestStartDemoHackStart(al::LiveActor*);
void requestEndDemoHackStart(const al::LiveActor*);
bool requestStartDemoAppearByBazookaElectric(al::LiveActor*);
void requestEndDemoAppearByBazookaElectric(const al::LiveActor*);
bool requestStartDemoLaunchBazookaElectric(al::LiveActor*);
void requestEndDemoLaunchBazookaElectric(const al::LiveActor*);
bool requestStartDemoSceneStartPlayerWalk(al::LiveActor*);
void requestEndDemoSceneStartPlayerWalk(const al::LiveActor*);
bool requestStartDemoGetLifeMaxUpItem(al::LiveActor*);
void requestEndDemoGetLifeMaxUpItem(const al::Scene*);
bool requestStartDemoBirdCarryMeat(al::LiveActor*);
void requestEndDemoBirdCarryMeat(const al::LiveActor*);
bool requestStartDemoBirdFindMeat(al::LiveActor*);
void requestEndDemoBirdFindMeat(const al::LiveActor*);
bool requestStartDemoGetTimeBalloon(al::LiveActor*);
void requestEndDemoGetTimeBalloon(const al::LiveActor*);
bool requestStartDemoJango(al::LiveActor*);
void requestEndDemoJango(const al::LiveActor*);
bool requestStartDemoTitleLogo(const al::LiveActor*);
bool requestStartDemoGoToEnding(al::LiveActor*);

bool isActiveDemo(const al::LiveActor*);
bool isActiveDemo(const al::Scene*);
bool isActiveDemoNormal(const al::Scene*);
bool isActiveDemoNormalWithCinemaFrame(const al::Scene*);
bool isActiveDemoWithPlayer(const al::Scene*);
bool isActiveDemoWithPlayer(const al::LiveActor*);
bool isActiveDemoWithPlayerCinemaFrame(const al::Scene*);
bool isActiveDemoWithPlayerCinemaFrame(const al::LiveActor*);
bool isActiveDemoWithPlayerKeepCarry(const al::Scene*);
bool isActiveDemoWithPlayerKeepCarry(const al::LiveActor*);
bool isActiveDemoWithPlayerUseCoin(const al::Scene*);
bool isActiveDemoWithPlayerUseCoin(const al::LiveActor*);
bool isActiveDemoWithPlayerKeepBindTalk(const al::Scene*);
bool isActiveDemoWithPlayerKeepBindTalk(const al::LiveActor*);
bool isActiveDemoWarpToCheckpoint(const al::LiveActor*);
bool isActiveDemoShineGet(const al::Scene*);
bool isActiveDemoShineGet(const al::LiveActor*);
bool isActiveDemoShineDotGet(const al::Scene*);
bool isActiveDemoShineDotGet(const al::LiveActor*);
bool isActiveDemoShineGrandGet(const al::Scene*);
bool isActiveDemoShineGrandGet(const al::LiveActor*);
bool isActiveDemoShineMainGet(const al::Scene*);
bool isActiveDemoShineMainGet(const al::LiveActor*);
bool isActiveDemoWarp(const al::Scene*);
bool isActiveDemoWarp(const al::LiveActor*);
bool isActiveDemoHackStart(const al::LiveActor*);
bool isActiveDemoHackStart(const al::Scene*);
bool isActiveDemoHackStartFirst(const al::Scene*);
bool isEqualDemoInfoDemoName(const al::Scene*, const char*);
bool isActiveDemoScenarioCamera(const al::LiveActor*);
bool isActiveDemoGetLifeMaxUpItem(const al::Scene*);
bool isActiveDemoSceneStartPlayerWalk(const al::Scene*);
bool isActiveDemoBirdCarryMeat(const al::Scene*);
bool isActiveDemoBirdFindMeat(const al::Scene*);
bool isActiveDemoJango(const al::Scene*);
bool isActiveDemoJango(const al::LiveActor*);
bool isActiveDemoTitleLogo(const al::Scene*);
bool isActiveDemoGoToEnding(const al::Scene*);
bool isActiveDemoTalk(const al::Scene*);
bool isActiveDemoCinemaFrameTalk(const al::Scene*);
bool isActiveDemoKeepCarryTalk(const al::Scene*);
bool isActiveDemoUseCoinTalk(const al::Scene*);
bool isActiveDemoKeepHackTalk(const al::Scene*);
bool isActiveDemoNormalTalk(const al::Scene*);
bool isActiveDemoLaunchBazookaElectric(const al::Scene*);
bool isActiveDemoGiantWanderBossBattleStart(const al::Scene*);
bool isActiveDemoGiantWanderBossBattleStart(const OceanWaveActor*);
bool isActiveDemoPlayerPuppetable(const al::LiveActor*);

void addDemoSubActor(al::LiveActor*);
void registerShineTowerRocketToDemoDirector(ShineTowerRocket*);
ShineTowerRocket* tryGetShineTowerRocketFromDemoDirector(al::LiveActor*);
void addDemoAppearFromHomeToList(ShineTowerRocket*);
void addDemoReturnToHomeToList(ShineTowerRocket*);
void addDemoRiseMapPartsToList(RiseMapPartsHolder*);

bool requestStartDemoWorldIntroCamera(const al::Scene*);
void requestEndDemoWorldIntroCamera(const al::Scene*);
bool requestStartDemoScenarioCamera(const al::Scene*);
void requestEndDemoScenarioCamera(const al::LiveActor*);
bool requestStartDemoAppearFromHome(const al::Scene*);
void requestEndDemoAppearFromHome(const al::LiveActor*);
bool requestStartDemoReturnToHome(const al::Scene*);
void requestEndDemoReturnToHome(const al::LiveActor*);
bool requestStartDemoRiseMapParts(const al::Scene*);
void requestEndDemoRiseMapParts(const al::LiveActor*);
bool requestStartDemoPeachCastleCap(al::LiveActor*);
void requestEndDemoPeachCastleCap(const al::LiveActor*);

bool isExistDemoAppearFromHomeInList(const al::Scene*);
bool isExistDemoReturnToHome(const al::Scene*);
bool isExistDemoRiseMapPartsInList(const al::Scene*);

al::LiveActor* getRequestActor(const al::Scene*);
void requestValidateDemoSkip(IUseDemoSkip*, const al::LiveActor*);
IUseDemoSkip* getDemoSkipRequester(const al::Scene*);
bool isDemoEnableSkip(const al::Scene*);
bool isFirstDemo(const al::Scene*);
bool isEnableSkipDemo(const al::Scene*);
void skipDemo(const al::Scene*);
void updateOnlyDemoGraphics(const al::Scene*);
bool isFirstDemoWorldIntroCamera(const al::Scene*);
bool isFirstDemoScenarioStartCamera(const al::LiveActor*);
void noticeDemoSkipStart(const al::Scene*);
void noticeDemoSkipEnd(const al::Scene*);
bool isWaitDemoSkipEnd(const al::LiveActor*);
CaptionInfoHolder* createCaptionInfoHolder(const char*);
void validateDemoCaption(const al::LiveActor*, CaptionInfoHolder*);
bool isActiveDemoWithCinemaCaption(const al::Scene*);
bool tryAppearCinemaCaption(const al::Scene*, CinemaCaption*);
void startCloseDemoFade(const al::LiveActor*, s32);
void startOpenDemoFade(const al::LiveActor*, s32);
bool isDemoFadeCloseEnd(const al::LiveActor*);
bool isDemoFadeOpenEnd(const al::LiveActor*);
bool isDemoFadeWipeStateEnableOpenMenuOrSnapShotMode(const al::Scene*);
DemoHackFirstDirector* tryCreateDemoHackFirstDirector(al::LiveActor*, s32,
                                                      const al::ActorInitInfo&);
void noticeDemoStartToDemoHackFirstDirector(const al::Scene*);
void setBossBarrierField(BarrierField*);
BarrierField* tryGetBossBarrierField(const al::LiveActor*);
void setDemoEnvironmentChangeFlag(const al::Scene*, bool);
void setDemoEnvironmentChangeFlag(const al::LiveActor*, bool);
bool isDemoEnvironmentChange(const al::Scene*);
bool isDemoEnvironmentChange(const al::LiveActor*);
s32 getRandomActionIndexDemoChangeWorld(const al::LiveActor*);
void setDemoInfoDemoName(const al::Scene*, const char*);
void getDemoInfoDemoName(const al::LiveActor*);
bool isTriggerDemoCancel(const al::IUseSceneObjHolder*);
void updateDemoSystemOnly(const al::Scene*);
void notifyDisableUpdateCamera(const al::LiveActor*);
bool isDisableUpdateCamera(const al::Scene*);
}  // namespace rs
