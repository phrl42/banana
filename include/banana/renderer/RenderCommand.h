#pragma once

#include "utils/incs.h"
#include "renderer/Shader.h"
#include "renderer/Batch.h"

namespace banana
{
  class RenderCommand
  {
  public:
    virtual ~RenderCommand() = default;
    
    virtual void Clear() = 0;
    virtual void SetColor(glm::vec4 color) = 0;
    virtual void Update(void* window) = 0;
    virtual void Draw(unsigned int elementOffset, ShaderType type) = 0;
    virtual void Upload(std::shared_ptr<Batch> batch) = 0;

    static std::shared_ptr<RenderCommand> GetRenderCommand();
  };
};