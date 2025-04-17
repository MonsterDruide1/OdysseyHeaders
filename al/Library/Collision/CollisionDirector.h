#pragma once

#include <math/seadVector.h>

#include "Library/Execute/IUseExecutor.h"
#include "Library/HostIO/HioNode.h"

namespace sead {
template <typename A1>
class IDelegate1;
template <typename T>
class PtrArray;
}  // namespace sead

namespace al {
class CollisionParts;
class CollisionPartsFilterBase;
class CollisionPartsKeeperOctree;
class CollisionPartsKeeperPtrArray;
class ExecuteDirector;
class ICollisionPartsKeeper;
class TriangleFilterBase;
struct ArrowHitInfo;
struct DiskHitInfo;
struct HitInfo;
struct SphereHitInfo;

class CollisionDirector : public HioNode, public IUseExecutor {
public:
    CollisionDirector(ExecuteDirector* executeDirector);
    void setPartsKeeper(ICollisionPartsKeeper* partsKeeper);
    void endInit();
    void setPartsFilter(const CollisionPartsFilterBase*);
    void setTriFilter(const TriangleFilterBase*);
    bool checkStrikePoint(const sead::Vector3f&, HitInfo*);
    bool checkStrikeSphere(const sead::Vector3f&, f32, bool, const sead::Vector3f&);
    bool checkStrikeArrow(const sead::Vector3f&, const sead::Vector3f&);
    bool checkStrikeSphereForPlayer(const sead::Vector3f&, f32);
    bool checkStrikeDisk(const sead::Vector3f&, f32, f32, const sead::Vector3f&);
    sead::PtrArray<ArrowHitInfo>* getStrikeArrowInfo(u32 index);
    u32 getStrikeArrowInfoNum();
    sead::PtrArray<DiskHitInfo>* getStrikeSphereInfo(u32 index);
    u32 getStrikeSphereInfoNum();
    sead::PtrArray<SphereHitInfo>* getStrikeDiskInfo(u32 index);
    u32 getStrikeDiskInfoNum();
    void getSphereHitInfoArrayForCollider(SphereHitInfo** infoArray, u32* count);
    void getDiskHitInfoArrayForCollider(DiskHitInfo** infoArray, u32* count);
    void execute();
    void searchCollisionPartsWithSphere(const sead::Vector3f&, f32,
                                        sead::IDelegate1<CollisionParts*>&,
                                        const CollisionPartsFilterBase*);
    void validateCollisionPartsPtrArray(sead::PtrArray<CollisionParts>*);
    void invalidateCollisionPartsPtrArray();
    sead::PtrArray<CollisionParts>* getCollisionPartsPtrArray();

public:
    ICollisionPartsKeeper* mActivePartsKeeper;
    CollisionPartsKeeperOctree* mRootOctree;
    CollisionPartsKeeperPtrArray* mCollisionPartsKeeperPtrArray;
    CollisionPartsFilterBase* mCollisionPartsFilterBase;
    TriangleFilterBase* mTriangleFilterBase;
    sead::PtrArray<ArrowHitInfo>* mStrikeArrowHitInfos;
    sead::PtrArray<SphereHitInfo>* mStrikeSphereHitInfos;
    sead::PtrArray<DiskHitInfo>* mStrikeDiskHitInfos;
    SphereHitInfo* mSphereHitArray;
    DiskHitInfo* mDiskHitArray;
};
}  // namespace al
