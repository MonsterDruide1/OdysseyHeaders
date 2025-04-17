#pragma once

#include "Library/HostIO/HioNode.h"
#include "Library/Nerve/IUseNerve.h"

namespace al {
class Nerve;
class NerveKeeper;

class NerveExecutor : public IUseNerve, public HioNode {
public:
    NerveExecutor(const char* name);

    virtual NerveKeeper* getNerveKeeper() const;
    virtual ~NerveExecutor();

    void initNerve(const Nerve* nerve, s32 stateCount);
    void updateNerve();

public:
    NerveKeeper* mKeeper = nullptr;
};
}  // namespace al
