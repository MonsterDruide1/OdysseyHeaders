#pragma once

#include "Library/Nerve/NerveExecutor.h"

namespace al {
class NerveStateBase : public NerveExecutor {
public:
    NerveStateBase(const char* stateName);

    virtual void init();
    virtual void appear();
    virtual void kill();
    virtual bool update();
    virtual void control();

    void setDead(bool isDead) { mIsDead = isDead; }

    bool isDead() const { return mIsDead; }

public:
    bool mIsDead = true;
};

class LiveActor;

class ActorStateBase : public NerveStateBase {
public:
    ActorStateBase(const char* stateName, LiveActor* actor);

public:
    LiveActor* mActor;
};

template <class T>
class HostStateBase : public NerveStateBase {
public:
    HostStateBase(const char* name, T* host) : NerveStateBase(name), mHost(host) {}

    T* getHost() const { return mHost; }

public:
    T* mHost;
};

}  // namespace al
