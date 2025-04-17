#pragma once

namespace al {
class KeyRepeatCtrl {
public:
    KeyRepeatCtrl();

    void init(s32 initialMaxWait, s32 maxWait);
    void reset();
    void update(bool up, bool down);
    bool isDown() const;
    bool isUp() const;

public:
    s32 mInitialMaxWait;
    s32 mMaxWait;
    s32 mUpCounter;
    s32 mDownCounter;
    bool mIsEnableCounter;
};
}  // namespace al
