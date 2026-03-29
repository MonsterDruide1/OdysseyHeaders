#pragma once

#include "Platform/Core/RootObject.h"

namespace nn::nex {
class DDLDeclarations : public RootObject {
public:
    DDLDeclarations(bool);

    virtual ~DDLDeclarations();

    virtual void Init() = 0;

    void RegisterIfRequired();
    void Unregister();
    static void UnregisterAll();
    void LoadAll();
    void Load();
    void UnloadAll();
    void Unload();
    void ResetDOClassIDs();

    u32 mNumDecsLoaded;
    u8 DDLDeclarations_xC;
    u64 _10;
    bool _18;

    static DDLDeclarations* s_pFirstDDLDecl;
};
}  // namespace nn::nex
