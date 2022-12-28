// including twice does not matter, as we are using ifndef's
// it just makes it easier to read
#include "game.h"
#include "init.h"
#include "misc.h"
#include "render.h"

int init(void)
{
  // create an instance of our window
  BananaWindow window;

  // initialize our engine
  if(initEngine(0) == -1) return -1;

  // initialize our struct
  window.w = 500;
  window.h = 500;
  window.title = "";
  window.flags = SDL_WINDOW_OPENGL;

  // create a window and with it's context
  // pass the address of window, otherwise it would copy our instance, which would result in no changes
  if(initBWindow(&window) == -1) return -1;
  // one does not have to call setActiveWindow when only using one window
  // if you want to use a different window, call setActiveWindow and pass your window number
  // (starting from 0)
  
  BananaObject objectOne;
  
  objectOne.x = 0.0f;
  objectOne.y = 0.0f;
  objectOne.w = 1.0f;
  objectOne.h = 1.0f;

  objectOne.r = 1.0f;
  objectOne.g = -0.5f;
  objectOne.b = -1.0f;

  addObject(&objectOne);
  return 0;
}

void loop(Uint64 frameTime)
{

}
