#pragma once

#include "Platform/Core/DateTime.h"

namespace nn::nex {
class DateTime;
class String;

template <typename T>
void SpecialDeleteArray(T* ptr);

class Variant {
public:
    union Data {
        uint64_t uint64_t;
        int64_t int64_t;
        double d;
        bool b;
        char* str;

        Data() {}

        ~Data() {}
    };

    enum class Type : int32_t {
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
    Variant(int64_t);
    Variant(uint64_t);
    Variant(int32_t);
    Variant(uint32_t);
    Variant(double);
    Variant(bool);
    Variant(const String&);
    Variant(const char*);
    Variant(const DateTime&);
    Type GetType() const;
    uint64_t GetUInt64Value() const;
    int64_t GetInt64Value() const;
    int32_t GetInt32Value() const;
    uint32_t GetUInt32Value() const;
    double GetDoubleValue() const;
    bool GetBoolValue() const;
    String GetStringValue() const;
    DateTime GetDateTimeValue() const;
    bool operator==(const Variant&) const;
    Variant& operator=(Variant&&);
    bool operator!=(const Variant&) const;
    void Trace(uint32_t) const;

public:
    Data field_0;
    Type field_8;
};

}  // namespace nn::nex
