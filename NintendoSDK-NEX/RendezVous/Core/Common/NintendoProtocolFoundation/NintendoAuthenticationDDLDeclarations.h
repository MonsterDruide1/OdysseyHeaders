#pragma once

#include "DDLTypes/DDLDeclarations.h"

namespace nn::nex {
class NintendoAuthenticationDDLDeclarations : public DDLDeclarations {
public:
    virtual ~NintendoAuthenticationDDLDeclarations();
    virtual void Init();

    void Register();
};
}  // namespace nn::nex
