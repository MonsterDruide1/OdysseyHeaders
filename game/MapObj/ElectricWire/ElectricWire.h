#pragma once

#include "Library/LiveActor/LiveActor.h"

class ElectricWire : public al::LiveActor {
public:
    void tryUpdateDisplayModel();

    bool isElectricWireRadio() { return mIsElectricWireRadio; }

public:
    char pad1[0x1a1];
    bool mIsElectricWireRadio;
};
