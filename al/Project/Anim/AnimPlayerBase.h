#pragma once

#include "Library/HostIO/HioNode.h"

namespace al {
class AnimInfoTable;

class AnimPlayerBase : public HioNode {
public:
    AnimPlayerBase();

    virtual void updateLast() { _10 = false; }

    virtual bool calcNeedUpdateAnimNext() = 0;

    AnimInfoTable* getAnimInfoTable() { return mInfoTable; }

public:
    AnimInfoTable* mInfoTable = nullptr;
    bool _10 = false;
    bool _11 = false;
};
}  // namespace al
