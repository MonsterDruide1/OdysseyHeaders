#pragma once

#include <container/seadTList.h>

#include "Library/Draw/IUsePartsGraphics.h"

namespace al {

class GraphicsSystemInfo;

class PartsGraphics : public IUsePartsGraphics, public sead::TListNode<PartsGraphics*> {
public:
    PartsGraphics(GraphicsSystemInfo* gfxSysInfo);
};

static_assert(sizeof(PartsGraphics) == 0x28);

}  // namespace al
