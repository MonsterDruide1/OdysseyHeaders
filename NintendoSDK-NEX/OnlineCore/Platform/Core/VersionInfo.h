#pragma once

#include <nn/types.h>

namespace nn::nex {
class VersionInfo {
public:
    static const char* GetCopyrightString();
    static u16 V1();
    static u16 V2();
    static u16 V3();
    static u16 V4();
    static u32 VersionMajor();
    static u32 VersionMinor();
    static u32 ExtractFirstNumber(u32 versionNumber);
    static u32 ExtractSecondNumber(u32 versionNumber);
    static void Banner(const char*);
};
}  // namespace nn::nex
