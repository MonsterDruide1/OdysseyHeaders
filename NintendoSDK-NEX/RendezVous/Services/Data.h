#pragma once

#include "Platform/Core/RootObject.h"
#include "Platform/Core/String.h"

namespace nn::nex {
class Data;
class Message;

class _DDL_Data : public RootObject {
public:
    ~_DDL_Data() override {}

    virtual void Clone() const;
    virtual String GetDataType() const;
    virtual bool IsA(const String&) const;
    virtual bool IsAKindOf(const String&) const;
    virtual void StreamIn(Message*) const;
    virtual void StreamOut(Message*);

    void Add(Message*, const _DDL_Data&);
    void Extract(Message*, _DDL_Data*);
    Data* DynamicCast(Data*);
    const Data* DynamicCast(const Data*);
};

class Data : public _DDL_Data {
public:
    Data();

    ~Data() override;

    bool _8;
};
}  // namespace nn::nex
