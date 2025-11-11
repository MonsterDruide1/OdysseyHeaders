#pragma once

#include <math/seadVector.h>

namespace al {

class PadRumbleKeeper {
public:
    PadRumbleKeeper(s32 port);

public:
    s32 mPort;
};

}  // namespace al
