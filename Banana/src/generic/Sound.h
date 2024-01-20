#pragma once

#include "_Banana.h"

#include "miniaudio.h"

namespace Banana
{
  class Sound
  {
  public:
    Sound(const std::string& path_to_sound, bool loop = false);
    Sound(float val);

    void Change(const std::string& path_to_sound, bool loop = false);
    void Change(float val);
    
    void Start();
    void Stop();

    void SetVolume(float vol);
    float GetVolume();

    ~Sound();

  private:
    void InitSound(const std::string& path_to_sound, bool loop);
    ma_sound current_sound;
    std::string sound_path;
  };
};
