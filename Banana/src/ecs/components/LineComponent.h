#pragma once

#include "ecs/components/QuadComponent.h"

namespace Banana
{
  // default custom textures will use RGBA8
  struct Pixel
  {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
  };
  struct Line
  {
    std::vector<Pixel> pixel;
  };
  struct Screen
  {
    std::vector<Line> line;
    uint32_t width;
    uint32_t height;
  };
  
  class LineComponent : public Component
  {
  public:
    LineComponent(Screen &screen);
    
    void UpdateTileData();

    virtual ~LineComponent() = default;
    virtual void OnUpdate(float dt, const Transform &transform) override;

    uint32_t GetTextureID();

  private:
    Screen &screen;
    QuadComponent quad;

    uint32_t n;
    TextureSpecification spec;
  };
};
