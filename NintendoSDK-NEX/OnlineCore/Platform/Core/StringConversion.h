#pragma once

#include "nn/types.h"

namespace nn::nex::StringConversion {

void Utf8ToWideChar(const char*, wchar_t*, u64);
void WideCharToUtf8(const wchar_t*, char*, u64);
void Utf8ToChar16(const char*, char16_t*, u64);
void Char16ToUtf8(const char16_t*, char*, u64);
void GetNeedWideCharBufferSize(const char*);
void GetNeedUtf8BufferSize(const wchar_t*);
void GetNeedUtf8BufferSize(const char16_t*);
void ByteArrayToBase64(const unsigned char*, u64, char*, u64*);
void Base64ToByteArray(const char*, u64, unsigned char*, u64*);
void Char8_2T(const char*, char*, u64);
void T2Char8(const char*, char*, u64);
void T2Char8Alloc(const char*, char**);
void Utf8ToT(const char*, char*, u64);
void TToUtf8(const char*, char*, u64);
void GetTToUtf8BufferSize(const char*);
void T2Char16(const char*, char16_t*, u64);
void Char16_2T(const char16_t*, char*, u64);
void Char8ToUtf8Alloc(const char*, char**);
void WideCharToUtf8Alloc(const wchar_t*, char**);
void Utf8ToWideCharAlloc(const char*, wchar_t**);
void T2Char8Release(char*);
void Encode(const unsigned char*, u64, char*, u64);
void Decode(const char*, unsigned char*, u64);
void GetCharValue(char);
void StringToHex(const char*, unsigned char*, u64);
void HexToString(const unsigned char*, char*, u64);
void GetCharValue(wchar_t);
void StringToHex(const wchar_t*, unsigned char*, u64);
void HexToString(const unsigned char*, wchar_t*, u64);

}  // namespace nn::nex::StringConversion
