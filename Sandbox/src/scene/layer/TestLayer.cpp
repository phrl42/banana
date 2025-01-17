#include "scene/layer/TestLayer.h"

#include "renderer/Renderer2D.h"

#include "ecs/components/QuadComponent.h"
#include "ecs/components/TextComponent.h"

namespace SANDBOX
{
  TestLayer::TestLayer(const std::string& name)
    : name(name), sound(Banana::SoundFile("assets/sounds/menu.wav"))
  {
    ent.transform.pos = {-1, 0, 0};
    ent.transform.size = {0.2, 0.2, 0};
    //ent.transform.color = {1, 0.5, -1.0f, 1.0f};
    ent.transform.color = {1.0f, 1.0f, 1.0f, 1.0f};
    ent.transform.proj = Banana::Projection::NONE;

    //ent.AddComponent(new Banana::QuadComponent("assets/textures/banana.png"));
    ent.AddComponent(new Banana::TextComponent("autistic double"));
  }

  TestLayer::~TestLayer()
  {

  }

  void TestLayer::OnAttach()
  {

  }

  void TestLayer::OnDetach()
  {

  }


  void TestLayer::OnEvent(Banana::Event& event)
  {

  }

  void TestLayer::OnUpdate(float dt)
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
      sound.Start();
      texcomp->ChangeText("salad bombs");
    }
    
    if(Banana::Input::IsKeyPressed(KEY_J))
    {
      texcomp->ChangeText("salad bomb");
    }

    //ent.transform.rotation += 90 * dt;
    //ent.transform.rotation += 90 * dt;
    ent.Render(dt);
  }
};
