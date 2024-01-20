#include "renderer/Buffer.h"
#include "renderer/Renderer.h"

#include "platform/OpenGL/OpenGLBuffer.h"

namespace Banana
{
  Shr<VertexBuffer> VertexBuffer::Create(const BufferLayout& layout, uint32_t size)
  {
    switch(Renderer::GetAPI())
    {
    case RendererAPI::API::OpenGL:
    {
      return MakeShr<OpenGLVertexBuffer>(layout, size);
      break;
    }
    }
    ASSERT(true, "Could not determine RendererAPI in VertexBuffer");
    return nullptr;
  }

  Shr<IndexBuffer> IndexBuffer::Create(uint32_t* indices, uint32_t size)
  {
    switch(Renderer::GetAPI())
    {
    case RendererAPI::API::OpenGL:
    {
      return MakeShr<OpenGLIndexBuffer>(indices, size);
      break;
    }
    }
    ASSERT(true, "Could not determine RendererAPI in IndexBuffer");
    return nullptr;
  }

};
