#pragma once

namespace al {
class ByamlContainerHeader {
public:
    s32 getType() const;
    s32 getCount(bool isRev) const;

public:
    u32 mType;
};
}  // namespace al
