#pragma once

#include "Player/PlayerActorBase.h"
#include "Util/IUseDimension.h"

namespace al {
class FootPrintHolder;
class HitSensor;
class WaterSurfaceFinder;
}  // namespace al

class ComboCounter;
class PlayerInfo;
class PlayerConst;
class PlayerInput;
class PlayerTrigger;
class HackCap;
class ActorDimensionKeeper;
class PlayerModelHolder;
class PlayerModelChangerHakoniwa;
class PlayerAnimator;
class PlayerColliderHakoniwa;
class PlayerPuppet;
class PlayerAreaChecker;
class PlayerOxygen;
class PlayerDamageKeeper;
class PlayerDemoActionFlag;
class PlayerCapActionHistory;
class PlayerCapManHeroEyesControl;
class PlayerContinuousJump;
class PlayerContinuousLongJump;
class PlayerCounterAfterUpperPunch;
class PlayerCounterForceRun;
class PlayerCounterIceWater;
class PlayerCounterQuickTurnJump;
class PlayerWallActionHistory;
class PlayerBindKeeper;
class PlayerCarryKeeper;
class PlayerEquipmentUser;
class PlayerHackKeeper;
class PlayerFormSensorCollisionArranger;
class PlayerJumpMessageRequest;
class PlayerSandSinkAffect;
class PlayerSpinCapAttack;
class PlayerActionDiveInWater;
class PlayerEffect;
class PlayerEyeSensorHitHolder;
class PlayerPushReceiver;
class PlayerHitPush;
class PlayerExternalVelocity;
class PlayerJointControlKeeper;
class PlayerPainPartsKeeper;
class PlayerRecoverySafetyPoint;
class PlayerRippleGenerator;
class PlayerSeparateCapFlag;
class PlayerWetControl;
class PlayerStainControl;
class GaugeAir;
class WaterSurfaceShadow;
class WorldEndBorderKeeper;
class PlayerSeCtrl;

class PlayerStateWait;
class PlayerStateSquat;
class PlayerStateRunHakoniwa2D3D;
class PlayerStateSlope;
class PlayerStateRolling;
class PlayerStateSpinCap;
class PlayerStateJump;
class PlayerStateCapCatchPop;
class PlayerStateWallAir;
class PlayerStateWallCatch;
class PlayerStateGrabCeil;
class PlayerStatePoleClimb;
class PlayerStateHipDrop;
class PlayerStateHeadSliding;
class PlayerStateLongJump;
class PlayerStateFallHakoniwa;
class PlayerStateSandSink;
class ActorStateSandGeyser;
class PlayerStateRise;
class PlayerStateSwim;
class PlayerStateDamageLife;
class PlayerStateDamageSwim;
class PlayerStateDamageFire;
class PlayerStatePress;
class PlayerStateBind;
class PlayerStateHack;
class PlayerStateEndHack;
class PlayerStateCameraSubjective;
class PlayerStateAbyss;

class PlayerJudgeAirForceCount;
class PlayerJudgeCameraSubjective;
class PlayerJudgeCapCatchPop;
class PlayerJudgeDeadWipeStart;
class PlayerJudgeDirectRolling;
class PlayerJudgeEnableStandUp;
class PlayerJudgeForceLand;
class PlayerJudgeForceSlopeSlide;
class PlayerJudgeForceRolling;
class PlayerJudgeGrabCeil;
class PlayerJudgeInWater;
class PlayerJudgeInWater;
class PlayerJudgeInWater;
class PlayerJudgeInWater;
class PlayerJudgeInvalidateInputFall;
class PlayerJudgeLongFall;
class PlayerJudgeOutInWater;
class PlayerJudgeRecoveryLifeFast;
class PlayerJudgeSandSink;
class PlayerJudgeSpeedCheckFall;
class PlayerJudgeStartHipDrop;
class PlayerJudgeStartRise;
class PlayerJudgeStartRolling;
class PlayerJudgeStartRun;
class PlayerJudgeStartSquat;
class PlayerJudgeStartWaterSurfaceRun;
class PlayerJudgeSlopeSlide;
class PlayerJudgePoleClimb;
class PlayerJudgePreInputJump;
class PlayerJudgePreInputCapThrow;
class PlayerJudgePreInputHackAction;
class HackCapJudgePreInputHoveringJump;
class HackCapJudgePreInputSeparateThrow;
class HackCapJudgePreInputSeparateJump;
class PlayerJudgeWallCatch;
class PlayerJudgeWallCatchInputDir;
class PlayerJudgeWallHitDown;
class PlayerJudgeWallHitDownForceRun;
class PlayerJudgeWallHitDownRolling;
class PlayerJudgeWallKeep;

class PlayerActorHakoniwa : public PlayerActorBase, public IUseDimension {
public:
    PlayerActorHakoniwa(const char*);
    void initAfterPlacement() override;
    void movement() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void control() override;
    void updateCollider() override;
    void initPlayer(const al::ActorInitInfo&, const PlayerInitInfo&) override;
    u32 getPortNo() const override;
    IUsePlayerCollision* getPlayerCollision() const override;
    PlayerHackKeeper* getPlayerHackKeeper() const override;
    bool isEnableDemo() override;
    void startDemo() override;
    void endDemo() override;
    void startDemoPuppetable() override;
    void endDemoPuppetable() override;
    void startDemoShineGet() override;
    void endDemoShineGet() override;
    void startDemoMainShineGet() override;
    void endDemoMainShineGet() override;
    void startDemoHack() override;
    void endDemoHack() override;
    void startDemoKeepBind() override;
    void noticeDemoKeepBindExecute() override;
    void endDemoKeepBind() override;
    void startDemoKeepCarry() override;
    void endDemoKeepCarry() override;
    al::DemoActor* getDemoActor() override;
    PlayerAnimator* getDemoAnimator() override;
    bool isDamageStopDemo() const override;
    PlayerPuppet* getPlayerPuppet() override;
    PlayerInfo* getPlayerInfo() const override;
    bool checkDeathArea() override;
    void sendCollisionMsg() override;
    bool receivePushMsg(const al::SensorMsg*, al::HitSensor*, al::HitSensor*, f32) override;
    ActorDimensionKeeper* getActorDimensionKeeper() const override;

    void updateModelShadowDropLength();
    void executeAfterCapTarget();
    void syncSensorAndCollision();
    void checkDamageFromCollision();
    void executePreMovementNerveChange();
    void updateCarry();
    void setNerveOnGround();
    void startPlayerPuppet();
    void cancelHackPlayerPuppetDemo();
    void endPlayerPuppet();
    void exeWait();
    bool tryActionCapReturn();
    bool tryActionCapSpinAttack();
    void exeSquat();
    bool tryActionSeparateCapThrow();
    void exeRun();
    void exeSlope();
    void exeRolling();
    void exeSpinCap();
    bool tryChangeNerveFromAir();
    bool tryActionCapSpinAttackMiss();
    void exeJump();
    void exeCapCatchPop();
    void exeWallAir();
    void exeWallCatch();
    void exeGrabCeil();
    void exePoleClimb();
    void exeHipDrop();
    void exeHeadSliding();
    void exeLongJump();
    void exeFall();
    void exeSandSink();
    void exeSandGeyser();
    void exeRise();
    void exeSwim();
    void exeDamage();
    void exeDamageSwim();
    void exeDamageFire();
    void exePress();
    void exeHack();
    void exeEndHack();
    void exeBind();
    bool tryActionCapSpinAttackBindEnd();
    void exeDemo();
    void exeCamera();
    void exeAbyss();
    void exeDead();
    bool tryActionCapSpinAttackImpl(bool);

public:
    PlayerInfo* mInfo;
    PlayerConst* mConst;
    PlayerInput* mInput;
    PlayerTrigger* mTrigger;
    HackCap* mHackCap;
    ActorDimensionKeeper* mDimensionKeeper;
    PlayerModelHolder* mModelHolder;
    PlayerModelChangerHakoniwa* mModelChanger;
    PlayerAnimator* mAnimator;
    PlayerColliderHakoniwa* mCollider;
    PlayerPuppet* mPuppet;
    PlayerAreaChecker* mAreaChecker;
    al::WaterSurfaceFinder* mWaterSurfaceFinder;
    PlayerOxygen* mOxygen;
    PlayerDamageKeeper* mDamageKeeper;
    PlayerDemoActionFlag* mDemoActionFlag;
    PlayerCapActionHistory* mCapActionHistory;
    PlayerCapManHeroEyesControl* mCapManHeroEyesControl;
    PlayerContinuousJump* mContinuousJump;
    PlayerContinuousLongJump* mContinuousLongJump;
    PlayerCounterAfterUpperPunch* mCounterAfterUpperPunch;
    PlayerCounterForceRun* mCounterForceRun;
    PlayerCounterIceWater* mCounterIceWater;
    PlayerCounterQuickTurnJump* mCounterQuickTurnJump;
    PlayerWallActionHistory* mWallActionHistory;
    PlayerBindKeeper* mBindKeeper;
    PlayerCarryKeeper* mCarryKeeper;
    PlayerEquipmentUser* mEquipmentUser;
    PlayerHackKeeper* mHackKeeper;
    PlayerFormSensorCollisionArranger* mFormSensorCollisionArranger;
    PlayerJumpMessageRequest* mJumpMessageRequest;
    PlayerSandSinkAffect* mSandSinkAffect;
    PlayerSpinCapAttack* mSpinCapAttack;
    PlayerActionDiveInWater* mActionDiveInWater;
    PlayerEffect* mEffect;
    PlayerEyeSensorHitHolder* mEyeSensorHitHolder;
    PlayerPushReceiver* mPushReceiver;
    PlayerHitPush* mHitPush;
    PlayerExternalVelocity* mExternalVelocity;
    PlayerJointControlKeeper* mJointControlKeeper;
    PlayerPainPartsKeeper* mPainPartsKeeper;
    PlayerRecoverySafetyPoint* mRecoverySafetyPoint;
    PlayerRippleGenerator* mRippleGenerator;
    PlayerSeparateCapFlag* mSeparateCapFlag;
    PlayerWetControl* mWetControl;
    PlayerStainControl* mStainControl;
    al::FootPrintHolder* mFootPrintHolder;
    GaugeAir* mGaugeAir;
    WaterSurfaceShadow* mWaterSurfaceShadow;
    WorldEndBorderKeeper* mWorldEndBorderKeeper;
    ComboCounter* mComboCounter;
    PlayerSeCtrl* mSeCtrl;
    al::HitSensor* mBodyHitSensor;
    bool mIsLongShadow;
    PlayerStateWait* mStateWait;
    PlayerStateSquat* mStateSquat;
    PlayerStateRunHakoniwa2D3D* mStateRunHakoniwa2D3D;
    PlayerStateSlope* mStateSlope;
    PlayerStateRolling* mStateRolling;
    PlayerStateSpinCap* mStateSpinCap;
    PlayerStateJump* mStateJump;
    PlayerStateCapCatchPop* mStateCapCatchPop;
    PlayerStateWallAir* mStateWallAir;
    PlayerStateWallCatch* mStateWallCatch;
    PlayerStateGrabCeil* mStateGrabCeil;
    PlayerStatePoleClimb* mStatePoleClimb;
    PlayerStateHipDrop* mStateHipDrop;
    PlayerStateHeadSliding* mStateHeadSliding;
    PlayerStateLongJump* mStateLongJump;
    PlayerStateFallHakoniwa* mStateFallHakoniwa;
    PlayerStateSandSink* mStateSandSink;
    ActorStateSandGeyser* mActorStateSandGeyser;
    PlayerStateRise* mStateRise;
    PlayerStateSwim* mStateSwim;
    PlayerStateDamageLife* mStateDamageLife;
    PlayerStateDamageSwim* mStateDamageSwim;
    PlayerStateDamageFire* mStateDamageFire;
    PlayerStatePress* mStatePress;
    PlayerStateBind* mStateBind;
    PlayerStateHack* mStateHack;
    PlayerStateEndHack* mStateEndHack;
    PlayerStateCameraSubjective* mStateCameraSubjective;
    PlayerStateAbyss* mStateAbyss;
    PlayerJudgeAirForceCount* mJudgeAirForceCount;
    PlayerJudgeCameraSubjective* mJudgeCameraSubjective;
    PlayerJudgeCapCatchPop* mJudgeCapCatchPop;
    PlayerJudgeDeadWipeStart* mJudgeDeadWipeStart;
    PlayerJudgeDirectRolling* mJudgeDirectRolling;
    PlayerJudgeEnableStandUp* mJudgeEnableStandUp;
    PlayerJudgeForceLand* mJudgeForceLand;
    PlayerJudgeForceSlopeSlide* mJudgeForceSlopeSlide;
    PlayerJudgeForceRolling* mJudgeForceRolling;
    PlayerJudgeGrabCeil* mJudgeGrabCeil;
    PlayerJudgeInWater* mJudgeInWater[4];
    PlayerJudgeInvalidateInputFall* mJudgeInvalidateInputFall;
    PlayerJudgeLongFall* mJudgeLongFall;
    PlayerJudgeOutInWater* mJudgeOutInWater;
    PlayerJudgeRecoveryLifeFast* mJudgeRecoveryLifeFast;
    PlayerJudgeSandSink* mJudgeSandSink;
    PlayerJudgeSpeedCheckFall* mJudgeSpeedCheckFall;
    PlayerJudgeStartHipDrop* mJudgeStartHipDrop;
    PlayerJudgeStartRise* mJudgeStartRise;
    PlayerJudgeStartRolling* mJudgeStartRolling;
    PlayerJudgeStartRun* mJudgeStartRun;
    PlayerJudgeStartSquat* mJudgeStartSquat;
    PlayerJudgeStartWaterSurfaceRun* mJudgeStartWaterSurfaceRun;
    PlayerJudgeSlopeSlide* mJudgeSlopeSlide;
    PlayerJudgePoleClimb* mJudgePoleClimb;
    PlayerJudgePreInputJump* mJudgePreInputJump;
    PlayerJudgePreInputCapThrow* mJudgePreInputCapThrow;
    PlayerJudgePreInputHackAction* mJudgePreInputHackAction;
    HackCapJudgePreInputHoveringJump* mHackCapJudgePreInputHoveringJump;
    HackCapJudgePreInputSeparateThrow* mHackCapJudgePreInputSeparateThrow;
    HackCapJudgePreInputSeparateJump* mHackCapJudgePreInputSeparateJump;
    PlayerJudgeWallCatch* mJudgeWallCatch;
    PlayerJudgeWallCatchInputDir* mJudgeWallCatchInputDir;
    PlayerJudgeWallHitDown* mJudgeWallHitDown;
    PlayerJudgeWallHitDownForceRun* mJudgeWallHitDownForceRun;
    PlayerJudgeWallHitDownRolling* mJudgeWallHitDownRolling;
    PlayerJudgeWallKeep* mJudgeWallKeep;
    bool mIsReduceOxygen;
};
