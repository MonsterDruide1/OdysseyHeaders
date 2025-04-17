#pragma once

namespace al {
class Nerve;
class NerveStateBase;

class NerveStateCtrl {
public:
    struct State {
        NerveStateBase* state;
        const Nerve* nerve;
        const char* name;
    };

    NerveStateCtrl(s32 maxStates);

    void addState(NerveStateBase* state, const Nerve* nerve, const char* name);
    bool updateCurrentState();
    void startState(const Nerve* nerve);
    void update();

    State* findStateInfo(const Nerve* nerve);
    bool isCurrentStateEnd() const;
    void tryEndCurrentState();

public:
    s32 mMaxStates;
    s32 mStateCount = 0;
    State* mStates = nullptr;
    State* mCurrentState = nullptr;
};
}  // namespace al
