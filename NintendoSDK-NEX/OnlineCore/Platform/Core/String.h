#pragma once

#include "Platform/Core/RootObject.h"

namespace nn::nex {
template <typename T>
void* SpecialNewArray(u32, T*, u32);

template <typename T, T>
void StrCopy(T*, const T*, u64);

class String : public RootObject {
public:
    class NoAllocTag;

    String();
    String(String::NoAllocTag);
    String(const char*);
    String(const wchar_t*);
    String(const char16*);
    String(const String&);
    virtual ~String();

    void Format(const char*, ...);
    void CreateCopy(char**) const;
    void ReleaseCopy(char*);

    void operator=(const String&);
    void operator=(const char*);
    void operator=(const wchar_t*);
    void operator=(const char16_t*);
    void IsEqual(const char*, const char*);
    void operator<(const String&) const;
    void operator+=(const String&);

    void Truncate(u64) const;
    void GetLength() const;
    void Reserve(u64);
    void SetBufferPtr(char*);
    void SetStringToPreReservedBuffer(const char*);
    void GetWideCharLength() const;
    void CopyString(char*, u64) const;
    void CreateCopy(wchar_t**) const;
    void ReleaseCopy(wchar_t*);
    void CopyString(wchar_t*, u64) const;
    void CreateCopy(char16_t**) const;
    void ReleaseCopy(char16_t*);
    void CopyString(char16_t*, u64) const;
    void ToUpper();
    void ToLower();
    void FindSubstringCase(const char*, s32) const;
    void FindSubstringNoCase(const char*) const;
    void ByteArrayToBase64(const unsigned char*, u64, char*, u64);
    void Base64ToByteArray(const char*, u64, u8*, u64);
    void Base64ToByteArray(const String&, u8*, u64);
    void ContainsCase(const String&) const;
    void ToUInt64() const;
    void ContainsNoCase(const String&) const;
    void SetDefaultStringEncoding(u32);
    void Trace(u64);

    // operator const char*() const { return m_String; }
    const char* cstr() const { return m_String; }

public:
    const char* m_String;
};
}  // namespace nn::nex
