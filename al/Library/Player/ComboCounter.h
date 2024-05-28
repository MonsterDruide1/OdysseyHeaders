#pragma once

#include <basis/seadTypes.h>

namespace al {

class ComboCounter {
public:
    ComboCounter() {}
    
    virtual void increment() {
        mCombo++;
    }

public:
    s32 mCombo;
};
static_assert(sizeof(ComboCounter) == 0x10);

}
