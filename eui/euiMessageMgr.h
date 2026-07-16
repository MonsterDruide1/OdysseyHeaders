#pragma once

#include <gfx/seadColor.h>
#include <heap/seadDisposer.h>
#include <prim/seadRuntimeTypeInfo.h>
#include <prim/seadSafeString.h>

namespace eui {

class MessageSet;

class MessageMgr {
    SEAD_RTTI_BASE(MessageMgr);
    SEAD_SINGLETON_DISPOSER(MessageMgr);

public:
    class Archive;

public:
    MessageMgr();
    virtual ~MessageMgr();

    virtual void loadArchive(sead::Heap*, void*, u32);
    virtual void unloadArchive(void*);

    void initialize(sead::Heap*, u32 maxColors);
    void finalize();

    MessageSet* getLayoutMessageSet(const sead::SafeString&) const;
    MessageSet* getMessageSet(const sead::SafeString&) const;

    void setGradationColor(u32 idx, sead::Color4u8 top, sead::Color4u8 bottom);
    void setTextBoxWidthSizeOverColor(sead::Color4u8);

    void dumpLastGotMessageSetInfo();

public:
    void archiveDisposeCallback_(Archive*);

public:
    char unk[0x30];
};

static_assert(sizeof(MessageMgr) == 0x58);

}  // namespace eui
