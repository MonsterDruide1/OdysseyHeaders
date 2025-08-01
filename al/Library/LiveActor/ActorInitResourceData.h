#pragma once

#include "Project/Action/InitResourceDataAction.h"
#include "Project/Anim/InitResourceDataAnim.h"

namespace al {
class Resource;

class ActorInitResourceData {
public:
    ActorInitResourceData(Resource* res);

    InitResourceDataAnim* getAnimData() const { return mResDataAnim; }

    InitResourceDataAction* getDataAction() const { return mResDataAction; }

public:
    Resource* mResource;
    InitResourceDataAnim* mResDataAnim = nullptr;
    InitResourceDataAction* mResDataAction = nullptr;
};
}  // namespace al
