#pragma once

#include <cstdint>

#include "Platform/Core/RootObject.h"

namespace nn::nex {
enum SubSystemType : uint16_t {

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
        uint32_t lastError;
        uint32_t lastExtError;
    };

    // made up struct
    struct ErrorCode {
        uint32_t code;

        ErrorCode() {}

        ErrorCode(uint32_t c) : code(c) {}

        enum Status : uint8_t { Success = 0, Informational = 1, Warning = 2, Error = 3 };

        Status GetStatus() const { return (Status)(code >> 30); }

        uint16_t GetSubsystem() const { return (code >> 16) & 0xFFF; }

        uint16_t GetDetail() const { return code & 0xFFFF; }

        bool IsSuccess() const { return GetStatus() == Success; }

        bool IsInformational() const { return GetStatus() == Informational; }

        bool IsWarning() const { return GetStatus() == Warning; }

        bool IsError() const { return GetStatus() == Error; }
    };

    constexpr uint32_t MakeErrorCode(ErrorCode::Status status, SubSystemType subsystem,
                                     uint16_t detail) {
        return ((uint32_t)status << 30) | ((uint32_t)subsystem << 16) | detail;
    }

    SystemError() = default;

    SystemError(const char* errorString, unsigned int errorCode);
    virtual ~SystemError();

    SystemError SetErrorInfo(unsigned int lastError, unsigned int lastExtError);
    void Trace(unsigned long);
    void ClearLast();
    int GetLast();
    int GetLastExt();

    static void GetErrorString(uint32_t errorCode, char* buffer, uint32_t bufferSize);
    static void SignalError(const char*, uint32_t, uint32_t lastError, uint32_t lastExtError);
    static void EraseErrorElements(unsigned long);
    static void EraseErrorElements();
    static void EraseAllErrorElements();
    static bool IsError();
    static bool IsError(uint32_t errorCode);
    static bool IsWarning(uint32_t errorCode);
    static bool IsInformational(uint32_t errorCode);
    static bool IsSuccess(uint32_t errorCode);
    void TraceLast(unsigned long);

public:
    ErrorInfo m_ErrorInfo;
    const char* m_ErrorString;
    ErrorCode m_ErrorCode;
};
}  // namespace nn::nex

extern nn::nex::ErrorDescriptionTable* g_SubsystemErrorsTable[];
