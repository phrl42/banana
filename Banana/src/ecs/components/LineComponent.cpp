#include "incs.h"
#include "ecs/components/LineComponent.h"

namespace Banana
{
  LineComponent::LineComponent(Screen &screen)
    :screen(screen)
  {
    this->name = "LineComponent";

    this->spec.width = screen.width;
    this->spec.height = screen.height;

    this->spec.size = screen.width * screen.height * 4;
    this->spec.format = ImageFormat::RGBA8;

    this->spec.data = (void*)screen.line.data();
    
    this->quad = QuadComponent(&spec);

    UpdateTileData();
  }

  uint32_t LineComponent::GetTextureID()
  {
    return quad.GetTextureID();
  }
 
  void LineComponent::UpdateTileData()
  {
    spec.data = (void*)screen.line.data();
    quad.UpdateTexture(); 
  }

  void LineComponent::OnUpdate(float dt, const Transform &transform)
  {
    UpdateTileData();
    quad.OnUpdate(dt, transform);
  }
};
