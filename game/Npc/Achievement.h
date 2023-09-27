#pragma once

#include "System/GameDataHolderAccessor.h"

class AchievementInfo;

class Achievement {
public:
    Achievement(const AchievementInfo*);
    bool isGet(GameDataHolderAccessor) const;

public:
    bool mGet = false;
    const AchievementInfo* mInfo;
};
