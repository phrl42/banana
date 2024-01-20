#include "renderer/RendererAPI.h"

namespace Banana
{
  #ifdef MACRO_OPENGL
  RendererAPI::API RendererAPI::api = RendererAPI::API::OpenGL;
  #else
  ASSERT(true, "MACRO_OPENGL NOT DEFINED");
  #endif
};
