#pragma once

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class CoinBlow : public al::LiveActor {
public:
    CoinBlow(const char* name);

    void init(const al::ActorInitInfo& info) override;

    void listenStart();

public:
    const char* mBlowSize = nullptr;
};
