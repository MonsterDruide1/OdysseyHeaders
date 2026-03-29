#pragma once

#include <nn/types.h>

namespace nn::nex {

class ConsoleIO {
public:
    static bool InputIsSupported();
    static bool OutputIsSupported();
    static u8 GetChar(bool unk);
    static void GetCStr(char* ret, u32 unk);
    static void Print(const char* str, ...);
    static void PutString(const char* str);
    static void Banner(const char* str);
    static void Error();
};

}  // namespace nn::nex
