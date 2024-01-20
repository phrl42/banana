#pragma once

#include "_Banana.h"
#include "Window.hpp"
#include "layer/Layer.h"
#include "layer/SceneStack.h"

#include "renderer/Framebuffer.h"
#include "generic/Sound.h"

namespace Banana
{
  class Application
  {
  public:
    Application();
    virtual ~Application();

    void OnEvent(Event& e);
    void Run();

    void PushScene(Scene* scene);
    
    void PopScene(Scene* scene);

    inline Window& GetWindow() { return *window; }

    inline static Application& GetInstance() { return *Instance; }

    inline ma_engine& Get_Sound_Engine() { return sound_helper.engine; }
  private:
    bool OnWindowClose(WindowCloseEvent& e);
    bool OnWindowResize(WindowResizeEvent& e);

    Layer* debug_layer;

    SceneStack scene_stack;
    std::unique_ptr<Window> window;

    static Application* Instance;

    bool running = true;
    bool minimized = false;
  public:
    Banana::Shr<Banana::Framebuffer> fb;

  private:
    struct SoundHelper
    {
    public:
      SoundHelper()
	{

	}

      void Init()
	{
	  LOG_DEBUG("Initialized Sound Helper");

	  int success = ma_engine_init(NULL, &engine);
	  ASSERT(success != MA_SUCCESS, std::string("Could not init engine: " + std::to_string(success)));

	  success = ma_engine_start(&engine);
	  ASSERT(success != MA_SUCCESS, std::string("Could not start engine: " + std::to_string(success)));
	}
      ~SoundHelper()
	{
	  LOG_DEBUG("Destroyed Sound Helper");
	  ma_engine_stop(&engine);
	  ma_engine_uninit(&engine);
	}
      ma_engine engine;
    };
    SoundHelper sound_helper;
  };

// definition is in client
  Application* CreateApplication();

};
