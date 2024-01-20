#include "platform/OpenGL/OpenGLTexture.h"

#include "renderer/Renderer.h"

namespace Banana
{
  Shr<Texture2D> Texture2D::Create(const std::string& path)
  {
    switch(Renderer::GetAPI())
    {
      case RendererAPI::API::OpenGL: return MakeShr<OpenGLTexture2D>(path);
    }

    ASSERT(true, "Could not find RendererAPI in Texture2D");
    return nullptr;
  }
  
  Shr<Texture2D> Texture2D::Create(const TextureSpecification& spec)
  {
    switch(Renderer::GetAPI())
    {
      case RendererAPI::API::OpenGL: return MakeShr<OpenGLTexture2D>(spec);
    }

    ASSERT(true, "Could not find RendererAPI in Texture2D");
    return nullptr;
  }

  Shr<Texture2D> Texture2D::Create(TextureSpecification* spec)
  {
    switch(Renderer::GetAPI())
    {
      case RendererAPI::API::OpenGL: return MakeShr<OpenGLTexture2D>(spec);
    }

    ASSERT(true, "Could not find RendererAPI in Texture2D");
    return nullptr;
  }

};
