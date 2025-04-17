#pragma once

namespace al {
struct AudioSystemInfo;
class BgmDirector;
struct BgmUserInfo;

class BgmKeeper {
public:
    static BgmKeeper* create(const AudioSystemInfo*, BgmDirector*, const char*);

    BgmKeeper(const AudioSystemInfo*, BgmDirector*, const char*);

    const char* getUserName() const;
    void update();

public:
    BgmDirector* mBgmDirector;
    BgmUserInfo* mBgmUserInfo = nullptr;
};
}  // namespace al
