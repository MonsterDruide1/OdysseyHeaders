#pragma once

#include "Platform/Core/RootObject.h"

namespace nn::nex {

class EventLog : public RootObject {
public:
    enum LogLevel { _0, _1, _2 };
};

void _QLOG(EventLog::LogLevel, const char*, ...);

}  // namespace nn::nex
