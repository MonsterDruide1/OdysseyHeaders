#pragma once

#include <heap/seadDisposer.h>

namespace sead {
class Heap;
}  // namespace sead

namespace al {
class AccountHolder;
class GameFrameworkNx;
class SystemKit;
struct DrawSystemInfo;
}  // namespace al

class RootTask;

class Application {
    SEAD_SINGLETON_DISPOSER(Application);

public:
    Application();
    void init(s32 argc, char** argv);
    void run();
    RootTask* getRootTask() const;

    al::SystemKit* getSystemKit() const { return mSystemKit; }

    al::GameFrameworkNx* getGameFramework() const { return mGameFramework; }

    al::DrawSystemInfo* getDrawSystemInfo() const { return mDrawSystemInfo; }

    al::AccountHolder* getAccountHolder() const { return mAccountHolder; }

public:
    friend class ApplicationFunction;

public:
    al::SystemKit* mSystemKit;
    al::GameFrameworkNx* mGameFramework;
    al::DrawSystemInfo* mDrawSystemInfo;
    al::AccountHolder* mAccountHolder;
};
