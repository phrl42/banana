#include "platform/OpenGL/OpenGLFramebuffer.h"
#include "renderer/Renderer.h"

namespace Banana
{
  Shr<Framebuffer> Framebuffer::Create(const FramebufferProperties& fb)
  {
    switch(Renderer::GetAPI())
    {
      case RendererAPI::API::OpenGL: return MakeShr<OpenGLFramebuffer>(fb);
    }
    
    ASSERT(true, "Could not determine RendererAPI in Framebuffer");
    return nullptr;
  }
};
