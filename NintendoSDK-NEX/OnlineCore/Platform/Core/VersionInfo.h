#pragma once

#include <cstdint>

namespace nn::nex {
class VersionInfo {
public:
    static const char* GetCopyrightString();
    static uint16_t V1();
    static uint16_t V2();
    static uint16_t V3();
    static uint16_t V4();
    static uint32_t VersionMajor();
    static uint32_t VersionMinor();
    static uint32_t ExtractFirstNumber(uint32_t versionNumber);
    static uint32_t ExtractSecondNumber(uint32_t versionNumber);
    static void Banner(const char*);
};
}  // namespace nn::nex
