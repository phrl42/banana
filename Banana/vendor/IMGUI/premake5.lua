project "IMGUI"
	kind "StaticLib"
	language "C++"
    staticruntime "off"

    targetdir "%{wks.location}/bin/target/%{cfg.buildcfg}/%{prj.name}"
    objdir "%{wks.location}/bin/obj/%{cfg.buildcfg}/%{prj.name}"

    includedirs{
      "%{prj.location}",
      "%{IncludeDir.GLFW}"
    }

    files{
      "imconfig.h",
      "imgui.h",
      "imgui.cpp",
      "imgui_draw.cpp",
      "imgui_internal.h",
      "imgui_tables.cpp",
      "imgui_widgets.cpp",
      "imstb_rectpack.h",
      "imstb_textedit.h",
      "imstb_truetype.h",
      "imgui_demo.cpp",
      "backends/imgui_impl_opengl3.cpp",
      "backends/imgui_impl_opengl3.h",
      "backends/imgui_impl_glfw.cpp",
      "backends/imgui_impl_glfw.h"
    }

	filter "system:windows"
		systemversion "latest"
		cppdialect "C++17"

	filter "system:linux"
		pic "On"
		systemversion "latest"
		cppdialect "C++17"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"

    filter "configurations:Dist"
		runtime "Release"
		optimize "on"
        symbols "off"
