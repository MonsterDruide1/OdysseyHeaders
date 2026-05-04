#pragma once

#include <basis/seadTypes.h>

namespace al {

class DemoActorHolder {
public:
    void kill();
    void startSequence();
    void updateSequence();
    bool isEndSequence() const;
    void updateGraphics();

    bool isAlive() const { return mIsAlive; }

public:
    u8 _0[0x4c];
    bool mIsAlive;
};

}  // namespace al
