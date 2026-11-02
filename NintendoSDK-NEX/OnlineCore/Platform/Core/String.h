#pragma once

#include <cstdint>

#include "Platform/Core/RootObject.h"

namespace nn::nex {
template <typename T>
void* SpecialNewArray(uint32_t, T*, uint32_t);

template <typename T, T>
void StrCopy(T*, const T*, uint64_t);

class String : public RootObject {
public:
    class NoAllocTag;

    String();
    String(String::NoAllocTag);
    String(const char*);
    String(const wchar_t*);
    String(const char16_t*);
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

    void Truncate(uint64_t) const;
    void GetLength() const;
    void Reserve(uint64_t);
    void SetBufferPtr(char*);
    void SetStringToPreReservedBuffer(const char*);
    void GetWideCharLength() const;
    void CopyString(char*, uint64_t) const;
    void CreateCopy(wchar_t**) const;
    void ReleaseCopy(wchar_t*);
    void CopyString(wchar_t*, uint64_t) const;
    void CreateCopy(char16_t**) const;
    void ReleaseCopy(char16_t*);
    void CopyString(char16_t*, uint64_t) const;
    void ToUpper();
    void ToLower();
    void FindSubstringCase(const char*, int32_t) const;
    void FindSubstringNoCase(const char*) const;
    void ByteArrayToBase64(const unsigned char*, uint64_t, char*, uint64_t);
    void Base64ToByteArray(const char*, uint64_t, uint8_t*, uint64_t);
    void Base64ToByteArray(const String&, uint8_t*, uint64_t);
    void ContainsCase(const String&) const;
    void ToUInt64() const;
    void ContainsNoCase(const String&) const;
    void SetDefaultStringEncoding(uint32_t);
    void Trace(uint64_t);

    // operator const char*() const { return m_String; }
    const char* cstr() const { return m_String; }

public:
    const char* m_String;
};
}  // namespace nn::nex
