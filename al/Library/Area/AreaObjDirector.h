#pragma once

#include <math/seadVector.h>

namespace al {
class AreaInitInfo;
class AreaObj;
class AreaObjFactory;
class AreaObjGroup;
class AreaObjMtxConnecterHolder;

class AreaObjDirector {
public:
    AreaObjDirector();
    void init(const AreaObjFactory* factory);
    void endInit();
    void update();
    void placement(const AreaInitInfo& initInfo);
    void placement(const AreaInitInfo* initInfo, s32 initInfoCount);
    void createAreaObjGroup(const AreaInitInfo& initInfo);
    void createAreaObjGroupBuffer();
    void placementAreaObj(const AreaInitInfo& initInfo);
    AreaObjGroup* getAreaObjGroup(const char* name) const;
    bool isExistAreaGroup(const char* name) const;
    AreaObj* getInVolumeAreaObj(const char* name, const sead::Vector3f& position);
    AreaObjMtxConnecterHolder* getMtxConnecterHolder() const;

public:
    const AreaObjFactory* mFactory = nullptr;
    AreaObjMtxConnecterHolder* mMtxConnecterHolder = nullptr;
    AreaObjGroup** mAreaGroups = nullptr;
    u32 mAreaGroupCount = 0;
};
}  // namespace al
