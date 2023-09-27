#pragma once

#include "Library/Nerve/Nerve.h"
#include "Library/Nerve/NerveUtil.h"

namespace al {
class NerveAction : public Nerve {
    friend class alNerveFunction::NerveActionCollector;

public:
    NerveAction();
    virtual const char* getActionName() const = 0;

public:
    NerveAction* mNextAction = nullptr;
};
}  // namespace al
