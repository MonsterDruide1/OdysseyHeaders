#pragma once

namespace aal {

class IAudioFrameProcess {
public:
    virtual ~IAudioFrameProcess();

public:
    virtual void audioFrameProcess_();
};

}  // namespace aal
