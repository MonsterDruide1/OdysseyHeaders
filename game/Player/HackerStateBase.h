#pragma once

#include "Library/Nerve/NerveStateBase.h"

namespace al {
class LiveActor;
}  // namespace al

class IUsePlayerHack;

class HackerStateBase : public al::NerveStateBase {
public:
    HackerStateBase(const char* stateName, al::LiveActor* actor, IUsePlayerHack** hacker);

public:
    al::LiveActor* mActor = nullptr;
    IUsePlayerHack** mHacker = nullptr;
};

static_assert(sizeof(HackerStateBase) == 0x28);
