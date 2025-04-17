#pragma once

namespace al {
class AudioDirector;
}

class SceneAudioSystemPauseController {
public:
    SceneAudioSystemPauseController(al::AudioDirector*);
    void update();
    void tryResume();
    void pause(bool);
    void resume(s32);

public:
    void* filler[2];
};
