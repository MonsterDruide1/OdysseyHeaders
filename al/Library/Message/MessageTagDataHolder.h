#pragma once

#include <prim/seadSafeString.h>

namespace al {
class IUseMessageSystem;
class MessageTagDataBase;

class MessageTagDataHolder {
public:
    MessageTagDataHolder(s32 size);
    void registerMessageTagData(MessageTagDataBase*);
    void replaceMessage(sead::WBufferedSafeString*, const IUseMessageSystem*, const char16*) const;

public:
    const char** mMessageArray;
    s32 mSize;
    s32 mMaxSize;
};

}  // namespace al
