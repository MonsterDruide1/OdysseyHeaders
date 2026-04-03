#pragma once

#include "Platform/Core/RootObject.h"

namespace nn::nex {
class Plugin : public RootObject {
public:
    Plugin();
    virtual ~Plugin();

    virtual void pure_virtual1();
    virtual void pure_virtual2();
    virtual void pure_virtual3();
    virtual void pure_virtual4();
    virtual void pure_virtual5();
    virtual void pure_virtual6();
    virtual void pure_virtual7();
    virtual void pure_virtual8();
    virtual bool Initialize();
    virtual void ThreadAttach();
    virtual void ThreadDetach();
    virtual void Destroy();
    virtual void pure_virtual9();
    virtual void pure_virtual10();

    void Unload();
    void Trace(u64);
    void SetLibrary(void*);
    static Plugin* GetInstance();

public:
    static Plugin* s_pInstance;

    void* m_Library = nullptr;
};
}  // namespace nn::nex
