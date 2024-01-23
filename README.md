# Banana Game Engine

<p>This is an experimental game engine which I personally use to learn about graphics and game development.</p>

<p>It always annoyed me to re-write tedious sdl2 code to just make a game or a graphics demo, <b>which lead to this idea</b>. This is engine is not really a game engine but a graphics toolset that enables the user to straight-fowardly create games and get a grasp of how game studios internally work.</p>

<p>The engine breaks down to 2 simple things. 1. The engine itself <a href="https://codeberg.org/phrl42/banana/src/branch/main/Banana">Banana/</a> and 2. <a href="https://codeberg.org/phrl42/banana/src/branch/main/Sandbox">Sandbox/</a> which takes your game files. The existing code in <b>Sandbox/</b> is supplied as a 'tutorial' to this engine.</p>

<p>You have to put your <b>game source files into this engine</b>, unlike other engines which function as dynamic/static libraries of which you can't really interfere with. This gives the user the advantage to <b>modify the engine's source code as desired.</b></p>

<p>PS: The user should be able to <b>make some quite decent games</b>. Text, Sound, Squares with(out) textures are supported. I am planning to support more geometric shapes and 3D objects in the future. ( I also have to fix god damn miniaudio crashing all the time )</p>

# To Do:

- [x] input system
- [x] get an infrastructure to work
- [x] implement batch renderer
- [X] sound system
- [x] text rendering
- [x] fix sound system
- [ ] add scene / engine debugging stuff to imgui
- [ ] optimize Renderer2D
- [ ] circle renderer
- [ ] line renderer

- [x] have fun

# Build Instructions

# Linux 
In order to generate makefiles, run:

```premake5 gmake2```

Compile as follows:

```make```

Run game binary:

```bin/target/Debug/Sandbox/Sandbox```

# Info
This engine currently only works on linux. Windows support will be added soon.

I have been inspired by <a href="https://github.com/TheCherno/Hazel">Cherno</a> in terms of abstraction.

Feel free to contribute
