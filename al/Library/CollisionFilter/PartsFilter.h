#pragma once

namespace al {

class CollisionParts;
class LiveActor;
class HitSensor;

class CollisionPartsFilterBase {
public:
    virtual bool isInvalidParts(const CollisionParts& parts) const = 0;
};

class CollisionPartsFilterActor : public CollisionPartsFilterBase {
public:
    CollisionPartsFilterActor(const LiveActor* actor) : mActor(actor) {}

    bool isInvalidParts(const CollisionParts& parts) const override;

public:
    const LiveActor* mActor;
    bool mIsCompareEqual = true;
};

class CollisionPartsFilterSubActor : public CollisionPartsFilterBase {
public:
    CollisionPartsFilterSubActor(const LiveActor* actor) : mActor(actor) {}

    bool isInvalidParts(const CollisionParts& parts) const override;

public:
    const LiveActor* mActor;
};

class CollisionPartsFilterConnectedSensor : public CollisionPartsFilterBase {
public:
    CollisionPartsFilterConnectedSensor(const HitSensor* sensor) : mSensor(sensor) {}

    bool isInvalidParts(const CollisionParts& parts) const override;

public:
    const HitSensor* mSensor;
};

class CollisionPartsFilterSpecialPurpose : public CollisionPartsFilterBase {
public:
    CollisionPartsFilterSpecialPurpose(const char* specialPurpose)
        : mSpecialPurpose(specialPurpose) {}

    bool isInvalidParts(const CollisionParts& parts) const override;

public:
    const char* mSpecialPurpose;
};

class CollisionPartsFilterOnlySpecialPurpose : public CollisionPartsFilterBase {
public:
    CollisionPartsFilterOnlySpecialPurpose(const char* specialPurpose)
        : mSpecialPurpose(specialPurpose) {}

    bool isInvalidParts(const CollisionParts& parts) const override;

public:
    const char* mSpecialPurpose;
};

class CollisionPartsFilterIgnoreSpecialPurpose : public CollisionPartsFilterBase {
public:
    CollisionPartsFilterIgnoreSpecialPurpose(const char* specialPurpose)
        : mSpecialPurpose(specialPurpose) {}

    bool isInvalidParts(const CollisionParts& parts) const override;

public:
    const char* mSpecialPurpose;
};

class CollisionPartsFilterIgnoreOptionalPurpose : public CollisionPartsFilterBase {
public:
    CollisionPartsFilterIgnoreOptionalPurpose(const char* optionalPurpose)
        : mOptionalPurpose(optionalPurpose) {}

    bool isInvalidParts(const CollisionParts& parts) const override;

public:
    const char* mOptionalPurpose;
};

class CollisionPartsFilterFunc : public CollisionPartsFilterBase {
public:
    using DelegateFilter = bool (*)(const CollisionParts& parts);

    CollisionPartsFilterFunc(DelegateFilter filter) : mFilter(filter) {}

    bool isInvalidParts(const CollisionParts& parts) const override;

public:
    DelegateFilter mFilter;
};

class CollisionPartsFilterFuncSendMsg : public CollisionPartsFilterBase {
public:
    using DelegateFilter = bool (*)(const CollisionParts& parts, HitSensor* sensor);

    CollisionPartsFilterFuncSendMsg(DelegateFilter filter, HitSensor* sensor)
        : mFilter(filter), mSensor(sensor) {}

    bool isInvalidParts(const CollisionParts& parts) const override;

public:
    DelegateFilter mFilter;
    HitSensor* mSensor;
};

class CollisionPartsFilterMergePair : public CollisionPartsFilterBase {
public:
    CollisionPartsFilterMergePair(CollisionPartsFilterBase* firstFilter,
                                  CollisionPartsFilterBase* secondFilter)
        : mFirstFilter(firstFilter), mSecondFilter(secondFilter) {}

    bool isInvalidParts(const CollisionParts& parts) const override {
        return mFirstFilter->isInvalidParts(parts) || mSecondFilter->isInvalidParts(parts);
    }

public:
    CollisionPartsFilterBase* mFirstFilter;
    CollisionPartsFilterBase* mSecondFilter;
};

CollisionPartsFilterFunc*
createCollisionPartsFilterFunc(CollisionPartsFilterFunc::DelegateFilter filter);

CollisionPartsFilterFuncSendMsg*
createCollisionPartsFilterFuncSendMsg(CollisionPartsFilterFuncSendMsg::DelegateFilter filter,
                                      HitSensor* sensor);

CollisionPartsFilterConnectedSensor*
createCollisionPartsFilterConnectedSensor(const HitSensor* sensor);

}  // namespace al
