#pragma once

namespace al {
class InitResourceDataActionAnim;
class InitResourceDataAnim;
class Resource;

class InitResourceDataAction {
public:
    static InitResourceDataAction* tryCreate(Resource*, const InitResourceDataAnim*, const char*);

    InitResourceDataAction(Resource*, const InitResourceDataAnim*, const char*);
    void sortCtrlInfo();

    InitResourceDataActionAnim* getDataActionAnim() const { return mDataActionAnim; }

public:
    InitResourceDataActionAnim* mDataActionAnim;
};

}  // namespace al
