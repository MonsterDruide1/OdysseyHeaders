#pragma once

#include "Library/LiveActor/LiveActor.h"

class CoinBlow : public al::LiveActor {
public:
    CoinBlow(const char* name);

    void init(const al::ActorInitInfo& initInfo) override;

    void listenStart();

public:
    const char* mBlowSize = nullptr;
};
