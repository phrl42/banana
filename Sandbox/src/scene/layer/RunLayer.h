#pragma once

#include "Banana.h"
#include "renderer/Texture.h"
#include "generic/Sound/Sound.h"

namespace SANDBOX
{
  class RunLayer : public Banana::Layer
  {
  public:
    RunLayer(const std::string& name = "Layer");
    
    ~RunLayer() override;

    virtual void OnAttach() override;
    virtual void OnDetach() override;

    virtual void OnUpdate(float dt) override;
    virtual void OnEvent(Banana::Event& event) override;

    virtual inline std::string& GetName() override { return name; }
  
  private:
    std::string name;
    Banana::Entity ent;
  };

};
