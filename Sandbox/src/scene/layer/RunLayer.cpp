#include "scene/layer/RunLayer.h"

#include "renderer/Renderer2D.h"

#include "ecs/components/QuadComponent.h"
#include "ecs/components/TextComponent.h"

namespace SANDBOX
{
  RunLayer::RunLayer(const std::string& name)
    : name(name)
  {
    ent.transform.pos = {-1, 0, 0};
    ent.transform.size = {0.2, 0.2, 0};
    //ent.transform.color = {1, 0.5, -1.0f, 1.0f};
    ent.transform.color = {1.0f, 1.0f, 1.0f, 1.0f};
    ent.transform.proj = Banana::Projection::NONE;

    //ent.AddComponent(new Banana::QuadComponent("assets/textures/banana.png"));
    ent.AddComponent(new Banana::TextComponent("autistic trio"));
  }

  RunLayer::~RunLayer()
  {

  }

  void RunLayer::OnAttach()
  {

  }

  void RunLayer::OnDetach()
  {

  }


  void RunLayer::OnEvent(Banana::Event& event)
  {

  }

  void RunLayer::OnUpdate(float dt)
  {
    Banana::TextComponent* texcomp = (Banana::TextComponent*)ent.GetComponent("TextComponent");

    if(Banana::Input::IsKeyPressed(KEY_Y))
    {
      ent.transform.size.y += 2 * dt;
    }
    if(Banana::Input::IsKeyPressed(KEY_Z))
    {
      ent.transform.size.x += 2 * dt;
    }

    if(Banana::Input::IsKeyPressed(KEY_N))
    {
      texcomp->ChangeText("thunar bombs");
    }
    
    if(Banana::Input::IsKeyPressed(KEY_J))
    {
      texcomp->ChangeText("thunar bomb");
    }

    //ent.transform.rotation += 90 * dt;
    //ent.transform.rotation += 90 * dt;
    ent.Render(dt);
  }
};
