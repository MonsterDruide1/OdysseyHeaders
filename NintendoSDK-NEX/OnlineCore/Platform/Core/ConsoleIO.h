#pragma once

#include <cstdint>

namespace nn::nex {

class ConsoleIO {
public:
    static bool InputIsSupported();
    static bool OutputIsSupported();
    static uint8_t GetChar(bool unk);
    static void GetCStr(char* ret, uint32_t unk);
    static void Print(const char* str, ...);
    static void PutString(const char* str);
    static void Banner(const char* str);
    static void Error();
};

}  // namespace nn::nex
