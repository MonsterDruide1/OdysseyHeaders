#pragma once

#include <basis/seadTypes.h>

class PlayerCarryKeeper {
public:
    bool isThrowHold() const;

public:
    u8 padding[0x70];
};
