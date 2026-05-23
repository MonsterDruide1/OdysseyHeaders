#pragma once

#include "Library/Event/EventFlowNode.h"

class EventFlowNodeSessionWaitMusician : public al::EventFlowNode {
public:
    EventFlowNodeSessionWaitMusician(const char* name);

    void init(const al::EventFlowNodeInitInfo& info) override;
    void start() override;
    s32 getNextId() const override;

public:
    s32 mCount = 0;
};

static_assert(sizeof(EventFlowNodeSessionWaitMusician) == 0x70);
