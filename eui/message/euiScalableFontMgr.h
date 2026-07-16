#pragma once

#include <basis/seadTypes.h>
#include <prim/seadSafeString.h>
#include <thread/seadThread.h>

namespace nn::font {
class ScalableFont;
class TextureCache;
}  // namespace nn::font

namespace nn::ui2d {
class ResourceAccessor;
}

namespace eui {
class FontMgr;
class ScalableFontTextBoxEx;

class ScalableFontMgr {
    SEAD_SINGLETON_DISPOSER(ScalableFontMgr)
public:
    struct InitializeArg;

    ScalableFontMgr();
    virtual ~ScalableFontMgr();

    void initialize(const InitializeArg&);
    void update();
    void registFont(nn::ui2d::ResourceAccessor*);
    const nn::font::ScalableFont* getFont(const sead::SafeString&) const;
    nn::font::ScalableFont* getFont(const sead::SafeString&);
    bool isGlyphsReady(const char16*, u32, const nn::font::ScalableFont*, const eui::FontMgr*);
    bool registerGlyphs(const char16*, u32, const nn::font::ScalableFont*, const eui::FontMgr*,
                        s32);
    const char* findFontName(const nn::font::ScalableFont*) const;
    void reserveRegisterGlyphs(eui::ScalableFontTextBoxEx*);
    void dumpTextureCacheGlyphTreeMap() const;
    s32 getTextureCacheNoSpaceError() const;
    void clearNoSpaceError();

    bool is_55() const { return _55; }

public:
    bool registerGlyphs_(const char16*, u32, const nn::font::ScalableFont*, const eui::FontMgr*,
                         s32, bool);
    bool isNeedPlot_(char16, u32, u32);

    char filler[0x10];
    nn::font::TextureCache* _38;
    sead::Thread* _40;
    ScalableFontTextBoxEx* _48;
    s32 _50;
    bool _54;
    bool _55;
    bool _56;
};

static_assert(sizeof(ScalableFontMgr) == 0x58);

}  // namespace eui
