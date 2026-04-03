#pragma once

#include "nn/types.h"

namespace nn::nex {
class BadEvents {
public:
    static BadEvents* s_pInstance;

    enum _ID {};

    BadEvents();
    void Reset();
    ~BadEvents();

    void SetExpectedEvent(_ID id);
    static BadEvents* CreateInstance();
    static void DeleteInstance();
    void SignalEvent(_ID id);
    void ClearExpectedEvent(_ID id);
    bool IsExpected(_ID id) const;
    void ClearCount(_ID id);
    s32 GetCount(_ID id) const;
    static bool GlobalNewDeleteAllowed();
    static void Signal(_ID id);

    s32 field_0[10];
    s32 field_28;
};
}  // namespace nn::nex
