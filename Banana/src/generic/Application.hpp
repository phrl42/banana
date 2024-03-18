#pragma once

#include "_Banana.h"
#include "Window.hpp"
#include "imgui/IMGUILayer.h"
#include "layer/SceneStack.h"

#include "renderer/Framebuffer.h"
#include "generic/Sound/Sound.h"

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

  private:
    bool OnWindowClose(WindowCloseEvent& e);
    bool OnWindowResize(WindowResizeEvent& e);

    bool is_debug();

    SceneStack scene_stack;
    IMGUILayer* debug_layer;

    std::unique_ptr<Window> window;

    static Application* Instance;

    bool running = true;
    bool minimized = false;
  public:
    std::vector<uint32_t*> fb_ids;
  };

  // definition is in client
  Application* CreateApplication();

};
