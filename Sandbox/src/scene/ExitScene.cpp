#include "scene/ExitScene.h"
#include "scene/layer/RunLayer.h"
#include "layer/Layer.h"

#include "renderer/Renderer2D.h"

namespace SANDBOX
{
  ExitScene::ExitScene(const std::string& name)
  :name(name)
  {
    layer_stack.PushLayer(new RunLayer("Layer One"));
  }

  void ExitScene::OnAttach()
  {
    AttachLayer();
  }

  void ExitScene::OnUpdate(float dt)
  {
    static float x = 0;
    static float y = 0;
    static float z = -10;

    if(Banana::Input::IsKeyPressed(KEY_S))
    {
      y -= 10 * dt;
    }
    
    if(Banana::Input::IsKeyPressed(KEY_W))
    {
      y += 10 * dt;
    }
    
    if(Banana::Input::IsKeyPressed(KEY_A))
    {
      x -= 10 * dt;
    }

    if(Banana::Input::IsKeyPressed(KEY_D))
    {
      x += 10 * dt;
    }

    if(Banana::Input::IsKeyPressed(KEY_T))
    {
      z += 10 * dt;
    }

    if(Banana::Input::IsKeyPressed(KEY_G))
    {
      z -= 10 * dt;
    }

    cam.SetPosition({x, y, z});

    RenderLayer(dt);
  }

  void ExitScene::OnDetach()
  {
    DetachLayer();
  }

};
