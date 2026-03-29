#pragma once

#include "Platform/Core/DateTime.h"
#include "nn/types.h"

namespace nn::nex {
class DateTime;
class String;

template <typename T>
void SpecialDeleteArray(T* ptr);

class Variant {
public:
    union Data {
        u64 u64;
        s64 s64;
        f64 f64;
        bool b;
        char* str;

        Data() {}

        ~Data() {}
    };

    enum class Type : s32 {
        None = 0,
        Signed = 1,
        Double = 2,
        Bool = 3,
        String = 4,
        DateTime = 5,
        Unsigned = 6
    };

    Variant();
    Variant(const Variant&);
    void operator=(const Variant&);
    ~Variant();
    Variant(s64);
    Variant(u64);
    Variant(s32);
    Variant(u32);
    Variant(f64);
    Variant(bool);
    Variant(const String&);
    Variant(const char*);
    Variant(const DateTime&);
    Type GetType() const;
    u64 GetUInt64Value() const;
    s64 GetInt64Value() const;
    s32 GetInt32Value() const;
    u32 GetUInt32Value() const;
    f64 GetDoubleValue() const;
    bool GetBoolValue() const;
    String GetStringValue() const;
    DateTime GetDateTimeValue() const;
    bool operator==(const Variant&) const;
    Variant& operator=(Variant&&);
    bool operator!=(const Variant&) const;
    void Trace(u32) const;

public:
    Data field_0;
    Type field_8;
};

}  // namespace nn::nex
