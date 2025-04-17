#pragma once

#include <prim/seadSafeString.h>

namespace sead {
class CoreId;
class DelegateThread;
class Thread;
}  // namespace sead

namespace al {
class FunctorBase;

class AsyncFunctorThread {
public:
    AsyncFunctorThread(const sead::SafeString& functor_name, const FunctorBase& functor,
                       s32 priority, s32 stack_size, sead::CoreId id);
    virtual ~AsyncFunctorThread();

    void threadFunction(sead::Thread* unused_1, s64 unused_2);
    void start();
    bool isDone() const;

public:
    sead::DelegateThread* mDelegateThread = nullptr;
    FunctorBase* mFunctor = nullptr;
    bool mIsDone = true;
};

static_assert(sizeof(AsyncFunctorThread) == 0x20);
}  // namespace al
