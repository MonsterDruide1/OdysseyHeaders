#pragma once

#include <math/seadVector.h>

namespace al {
class LiveActor;
}
class PlayerWallActionHistory;

namespace rs {

bool judgeEnableWallKeepHistory(const al::LiveActor* player, const PlayerWallActionHistory* history,
                                const sead::Vector3f& calcPos, const sead::Vector3f& wallNormal, f32 unk, bool unk2);

}  // namespace rs
