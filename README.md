# Banana Game Engine

<p>This is an experimental game engine which I personally use to learn about graphics and game development.</p>

<p>It always annoyed me to re-write tedious sdl2 code to just make a game or a graphics demo, which lead to this idea. This is engine is not really a game engine but a graphics toolset that enables the user to straight-fowardly create games and get a grasp of how game studios internally work.</p>

<p>The engine breaks down to 2 simple things. One is the Engine itself ```Banana/*``` and the other is ```Sandbox/``` which takes your game files. The existing code in ```Sandbox/*``` is supplied as a 'tutorial' to this engine.</p>

<p>You have to put your game source files into this engine, unlike other engines which function as dynamic/static libraries of which you can't really interfere with. This gives the user the advantage to modify the engine's source code as desired.</p>

<p>PS: The user should be able to make some quite decent games. Text, Sound, Squares with(out) textures are supported. I am planning to support more geometric shapes and 3D objects in the future. ( I also have to fix god damn miniaudio crashing all the time )</p>

# To Do:

- [x] input system
- [x] get an infrastructure to work
- [x] implement batch renderer
- [X] sound system
- [x] text rendering
- [ ] fix sound system
- [ ] add scene / engine debugging stuff to imgui
- [ ] optimize Renderer2D
- [ ] circle renderer
- [ ] line renderer

- [x] have fun

# Instructions

In order to generate makefiles, run:

```premake5 gmake2```

Compile as follows:

```make```

Run game binary:

```bin/target/Debug/Sandbox/Sandbox```

# Info
I have been inspired by <a href="https://github.com/TheCherno/Hazel">Cherno</a> in terms of abstraction.

Feel free to contribute
