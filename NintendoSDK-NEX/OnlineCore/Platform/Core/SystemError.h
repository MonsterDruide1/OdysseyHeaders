#pragma once

#include "Platform/Core/RootObject.h"

namespace nn::nex {
enum SubSystemType : u16 {

};

class ErrorDescriptionTable : public nn::nex::RootObject {
public:
    ErrorDescriptionTable() {};
    ErrorDescriptionTable(const char**, SubSystemType);
    virtual ~ErrorDescriptionTable();

    const char** GetErrorTable() const { return mErrorTable; }

    SubSystemType GetSubSystemType() const { return mSubSystemType; }

public:
    SubSystemType mSubSystemType;
    const char** mErrorTable;
};

class SystemError : public nn::nex::RootObject {
public:
    struct ErrorInfo {
        u32 lastError;
        u32 lastExtError;
    };

    // made up struct
    struct ErrorCode {
        u32 code;

        ErrorCode() {}

        ErrorCode(u32 c) : code(c) {}

        enum Status : u8 { Success = 0, Informational = 1, Warning = 2, Error = 3 };

        Status GetStatus() const { return (Status)(code >> 30); }

        u16 GetSubsystem() const { return (code >> 16) & 0xFFF; }

        u16 GetDetail() const { return code & 0xFFFF; }

        bool IsSuccess() const { return GetStatus() == Success; }

        bool IsInformational() const { return GetStatus() == Informational; }

        bool IsWarning() const { return GetStatus() == Warning; }

        bool IsError() const { return GetStatus() == Error; }
    };

    constexpr u32 MakeErrorCode(ErrorCode::Status status, SubSystemType subsystem, u16 detail) {
        return ((u32)status << 30) | ((u32)subsystem << 16) | detail;
    }

    SystemError() = default;

    SystemError(const char* errorString, unsigned int errorCode);
    virtual ~SystemError();

    SystemError SetErrorInfo(unsigned int lastError, unsigned int lastExtError);
    void Trace(unsigned long);
    void ClearLast();
    int GetLast();
    int GetLastExt();

    static void GetErrorString(u32 errorCode, char* buffer, u32 bufferSize);
    static void SignalError(const char*, u32, u32 lastError, u32 lastExtError);
    static void EraseErrorElements(unsigned long);
    static void EraseErrorElements();
    static void EraseAllErrorElements();
    static bool IsError();
    static bool IsError(u32 errorCode);
    static bool IsWarning(u32 errorCode);
    static bool IsInformational(u32 errorCode);
    static bool IsSuccess(u32 errorCode);
    void TraceLast(unsigned long);

public:
    ErrorInfo m_ErrorInfo;
    const char* m_ErrorString;
    ErrorCode m_ErrorCode;
};
}  // namespace nn::nex

extern nn::nex::ErrorDescriptionTable* g_SubsystemErrorsTable[];
