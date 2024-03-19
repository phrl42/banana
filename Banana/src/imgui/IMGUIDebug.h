#pragma once
#include "_Banana.h"

namespace Banana
{
  struct IMGUIDebug
  {
    static inline uint32_t quad_count;
    static inline uint32_t texture_count;
    static inline uint32_t text_glyphs;

  private:
    IMGUIDebug();
    ~IMGUIDebug();
  };
};