#pragma once

namespace agl {
class TextureSampler;
}

namespace sead {
class Random;
}

namespace al {

class LutTexture;

class RandomTextureKeeper {
public:
    RandomTextureKeeper();
    ~RandomTextureKeeper();
    void makeRandomTexture();
    agl::TextureSampler* getRandomTex1DSampler() const;

public:
    LutTexture* mLutTexture;
    sead::Random* mRandom;
};

static_assert(sizeof(RandomTextureKeeper) == 0x10);

}  // namespace al
