#pragma once

#include <cstdint>

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
    int32_t GetCount(_ID id) const;
    static bool GlobalNewDeleteAllowed();
    static void Signal(_ID id);

    int32_t field_0[10];
    int32_t field_28;
};
}  // namespace nn::nex
