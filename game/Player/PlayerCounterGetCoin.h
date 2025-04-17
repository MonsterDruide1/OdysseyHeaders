#pragma once

class PlayerCounterGetCoin {
public:
    PlayerCounterGetCoin();

    f32 getCoinBoostRate() const;
    void countUp();
    void update();

public:
    s32 mTimer = 0;
    s32 mDuration = 0;
};
