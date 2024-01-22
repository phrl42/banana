#pragma once

#include "Banana.h"
#include "Sandbox.h"

namespace SANDBOX
{
  class ExitScene : public Banana::Scene
  {
  public:
    ExitScene(const std::string& name);

    ~ExitScene() override = default;

    virtual void OnAttach() override;
    virtual void OnDetach() override;

    virtual void OnUpdate(float dt) override;

  private:
    std::string name;
  };
};
