#pragma once

class PlayerConst;
class PlayerTrigger;

class PlayerCounterQuickTurnJump {
public:
    PlayerCounterQuickTurnJump(const PlayerConst* pConst, const PlayerTrigger* trigger);

    void update();
    bool isEnableTurnJump() const;

public:
    const PlayerConst* mConst;
    const PlayerTrigger* mTrigger;
    s32 mCounter = 0;
};
