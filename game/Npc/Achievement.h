#pragma once

#include "System/GameDataHolderAccessor.h"

struct AchievementInfo;

class Achievement {
public:
    Achievement(const AchievementInfo*);
    bool isGet(GameDataHolderAccessor) const;

public:
    bool mIsGet = false;
    const AchievementInfo* mInfo;
};
