#include "Application.hpp"
#include "imgui/IMGUILayer.h"
#include "event/KeyCode.h"
#include "event/Input.hpp"
#include "renderer/Renderer.h"
#include "renderer/RenderCommand.hpp"
#include "Font.h"

namespace Banana
{

  Application* Application::Instance = nullptr;

  Application::Application()
  {
    ASSERT(Instance, "Application already exists");

    Instance = this;

    WindowProps prop;
    prop.Title = "Banana Engine";
    prop.height = 1280;
    prop.width = 720;

    window = Window::Create(prop);

    window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));

    Renderer::Init();

    debug_layer = new Banana::IMGUILayer("IMGUILAYER");

    sound_helper.Init();
    //Text::Init("assets/fonts/mononoki.ttf");
  }

  void Application::OnEvent(Event& e)
  {
    EventDispatcher dispatcher(e);
    dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));
    dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FN(Application::OnWindowResize));

    for(auto it = scene_stack.end(); it != scene_stack.begin();)
    {
      (*--it)->OnEvent(e);

      if(e.handled)
      {
        break;
      }
    }
  }

  void Application::PopScene(Scene* scene)
  {
    scene_stack.PopScene(scene);
  }

  void Application::PushScene(Scene* scene)
  {
    scene_stack.PushScene(scene);
  }

  bool Application::OnWindowClose(WindowCloseEvent& e)
  {
    running = false;
    return true;
  }
  
  bool Application::OnWindowResize(WindowResizeEvent& e)
  {
    if(!e.getWidth() || !e.getHeight()) 
    {
      minimized = true;
      return false;
    }
    
    // tell opengl to resize framebuffer
    Renderer::OnWindowResize(e.getWidth(), e.getHeight());

    for(Scene* scene : scene_stack)
    {
      scene->fb->SetWindowDimension(e.getWidth(), e.getHeight());
    }

    minimized = false;
    return false;
  }


  void Application::Run()
  {
    for(Scene* scene : scene_stack)
    {
      scene->OnAttach();
      fb_ids.push_back(scene->fb->GetColorAttachmentID());
    }

    debug_layer->OnAttach();

    double begin_time = 0.0f;
    double dt = 0.1f;
    while(running)
    {
      begin_time = window->GetTime();
      window->PollEvents();

      RenderCommand::SetClearColor(glm::vec4(0, 0, 0, 0));
      RenderCommand::Clear();

      if(!minimized)
      { 
        // toggling
        static bool press = false;
        static bool debug = true;

        if(Input::IsKeyPressed(KEY_U) && !press)
        {
          press = true;
          debug = !debug;
        }

        if(!Input::IsKeyPressed(KEY_U))
        {
          press = false;
        }

        if(debug)
        {
          debug_layer->OnUpdate(dt);
        }
	// hack because I am tired 
	uint32_t i = 0;
        for(Scene* scene : scene_stack)
        {
	  scene->fb->Bind();
          scene->OnUpdate(dt);
	  scene->fb->Unbind();
	  fb_ids[i] = scene->fb->GetColorAttachmentID();
        }
      }
      
      window->SwapBuffers();

      dt = window->GetTime() - begin_time;
    }
    
    for(Scene* scene : scene_stack)
    {
      scene->OnDetach();
    }

    debug_layer->OnDetach();

    Renderer::Shutdown();
  }

  Application::~Application()
  {
    LOG_DEBUG("Destroying Application including Scenes");
  }

};
