#pragma once

namespace al {

class ExecutorListBase {
public:
    ExecutorListBase(const char*);

    virtual ~ExecutorListBase();
    virtual void executeList() const;
    virtual bool isActive() const;

public:
    const char* mName;
};

}  // namespace al
