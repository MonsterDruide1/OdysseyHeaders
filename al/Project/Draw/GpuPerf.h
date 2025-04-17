#pragma once

namespace sead {
class FrameBuffer;
}  // namespace sead

namespace agl {
class DrawContext;
}

namespace al {

class GpuPerf {
public:
    GpuPerf();

    void beginPerf(agl::DrawContext* drawContext);
    void endPerf(agl::DrawContext* drawContext);
    void update();
    void drawResult(agl::DrawContext* drawContext, const sead::FrameBuffer* frameBuffer) const;
};

}  // namespace al
