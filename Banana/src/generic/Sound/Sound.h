#pragma once
#include "_Banana.h"
#include "miniaudio.h"

namespace Banana
{
  class Sound
  {
  public: 
    void Start();
    void Stop();

    void SetVolume(float vol);
    float GetVolume();
  protected:
    Sound() = default;
    ~Sound();
    ma_sound current_sound;
  };

  class SoundFile : public Sound
  {
  public:
    SoundFile(const std::string& path_to_sound, bool loop = false);
    void Change(const std::string& path_to_sound, bool loop = false);

    ~SoundFile() = default;
  private:
    std::string sound_path;
    
  private:
    void InitSound(const std::string& path_to_sound, bool loop);
  };

  class SoundSample : public Sound
  {
  public:
    SoundSample();

  private:

  };

};
