#pragma once

#include <cstdint>

namespace nn::nex::StringConversion {

void Utf8ToWideChar(const char*, wchar_t*, uint64_t);
void WideCharToUtf8(const wchar_t*, char*, uint64_t);
void Utf8ToChar16(const char*, char16_t*, uint64_t);
void Char16ToUtf8(const char16_t*, char*, uint64_t);
void GetNeedWideCharBufferSize(const char*);
void GetNeedUtf8BufferSize(const wchar_t*);
void GetNeedUtf8BufferSize(const char16_t*);
void ByteArrayToBase64(const unsigned char*, uint64_t, char*, uint64_t*);
void Base64ToByteArray(const char*, uint64_t, unsigned char*, uint64_t*);
void Char8_2T(const char*, char*, uint64_t);
void T2Char8(const char*, char*, uint64_t);
void T2Char8Alloc(const char*, char**);
void Utf8ToT(const char*, char*, uint64_t);
void TToUtf8(const char*, char*, uint64_t);
void GetTToUtf8BufferSize(const char*);
void T2Char16(const char*, char16_t*, uint64_t);
void Char16_2T(const char16_t*, char*, uint64_t);
void Char8ToUtf8Alloc(const char*, char**);
void WideCharToUtf8Alloc(const wchar_t*, char**);
void Utf8ToWideCharAlloc(const char*, wchar_t**);
void T2Char8Release(char*);
void Encode(const unsigned char*, uint64_t, char*, uint64_t);
void Decode(const char*, unsigned char*, uint64_t);
void GetCharValue(char);
void StringToHex(const char*, unsigned char*, uint64_t);
void HexToString(const unsigned char*, char*, uint64_t);
void GetCharValue(wchar_t);
void StringToHex(const wchar_t*, unsigned char*, uint64_t);
void HexToString(const unsigned char*, wchar_t*, uint64_t);

}  // namespace nn::nex::StringConversion
