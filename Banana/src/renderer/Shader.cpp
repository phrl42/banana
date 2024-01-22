#include "platform/OpenGL/OpenGLShader.h"

#include "renderer/Renderer.h"

namespace Banana
{
  Shr<Shader> Shader::Create(const std::string& file_path)
  {
    switch(Renderer::GetAPI())
    {
      case RendererAPI::API::OpenGL: return MakeShr<OpenGLShader>(file_path);
    }

    ASSERT(true, "Could not determine RendererAPI in Shader");
    return nullptr;
  }
};
