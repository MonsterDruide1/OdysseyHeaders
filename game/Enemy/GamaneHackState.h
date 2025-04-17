#pragma once

#include <math/seadVector.h>

#include "Library/Nerve/NerveStateBase.h"

namespace al {
class HitSensor;
class LiveActor;
class SensorMsg;
struct ActorInitInfo;
}  // namespace al

class HackerJudgeNormalFall;
class HackerJudgeNormalJump;
class HackerJudgeStartRun;
class IUsePlayerHack;
class PlayerActionTurnControl;

class GamaneHackState : public al::ActorStateBase {
public:
    GamaneHackState(al::LiveActor*);

    void appear() override;
    void kill() override;

    void attackSensor(al::HitSensor* self, al::HitSensor* other);
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self);
    void initialize(const al::ActorInitInfo& info);
    bool isJump() const;
    void tryJump();
    bool isHackEnd() const;
    void updateMovement();
    bool judgeShoot();
    void shoot(s32);

    void exeWait();
    void exeMove();
    void exeQuickTurn();
    void exeFall();
    void exeJump();
    void exeLand();
    void exeSwingAttack();
    void exeEnd();

    void setPlayerHackAction(IUsePlayerHack* playerHackAction) { mPlayerHack = playerHackAction; }

    const sead::Vector3f& getVelocity() { return mVelocity; }

    void setVelocity(const sead::Vector3f& vector) { mVelocity.set(vector); }

public:
    HackerJudgeNormalFall* mJudgeNormalFall;
    HackerJudgeStartRun* mJudgeStartRun;
    HackerJudgeNormalJump* mJudgeNormalJump;
    PlayerActionTurnControl* mPlayerActionTurnControl;
    IUsePlayerHack* mPlayerHack;
    void** _48;
    s64 _50;
    s32 _58;
    s32 _5c;
    s32 _60;
    sead::Vector3f mVelocity;
};
