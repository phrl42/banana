#pragma once
#include "_Banana.h"

namespace Banana
{
  enum class IMGUIDebugType {NONE=0, TEXT};

  struct IMGUIDebug
  {
    IMGUIDebugType type;
    std::string text;
  };
};