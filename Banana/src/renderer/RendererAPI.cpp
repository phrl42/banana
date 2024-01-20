#include "renderer/RendererAPI.h"

namespace Banana
{
  #ifdef MACRO_OPENGL
  RendererAPI::API RendererAPI::api = RendererAPI::API::OpenGL;
  #else
  LOG("No Rendering API specified");
  exit(-1);
  #endif
};
