project(KrumbEngine)

set(KRUMB_ENGINE_SRC	"src/KrumbEngine/Application.cpp"
						"src/KrumbEngine/Application.h"
						"src/KrumbEngine/EntryPoint.h"
						"src/KrumbEngine/Logger.cpp"
						"src/KrumbEngine/Logger.h"
						"src/KrumbEngine/window/Window.cpp"
						"src/KrumbEngine/window/Window.h"
						"src/KrumbEngine/GL.h"
						"src/KrumbEngine/Core.h"
						"src/KrumbEngine/event/EventSystem.h"
						"src/KrumbEngine/event/EventSystem.cpp"
						"src/KrumbEngine/event/IEvent.h"
						"src/KrumbEngine/input/InputEvents.h"
						"src/KrumbEngine/window/WindowEvents.h"
						"src/KrumbEngine/GameSettings.h"
						"src/KrumbEngine/KrumbTime.h"
						"src/KrumbEngine/render/Shader.h"
						"src/KrumbEngine/render/Texture.h"
						"src/KrumbEngine/render/Texture.cpp"

						"src/KrumbEngine.h")

add_definitions(-DKMB_BUILD_DLL)
add_library(KrumbEngine SHARED "${KRUMB_ENGINE_SRC}")

target_include_directories(KrumbEngine PUBLIC	"src"
												"../lib/spdlog/include"
												"../lib/stb"
												glfw
												libglew_shared)
target_link_libraries(KrumbEngine PUBLIC glfw libglew_shared)

if (MCVS)
add_custom_command(TARGET KrumbEngine POST_BUILD        # Adds a post-build event to MyTest
    COMMAND ${CMAKE_COMMAND} -E copy_if_different  # which executes "cmake - E copy_if_different..."
        "${CMAKE_CURRENT_BINARY_DIR}/Debug/KrumbEngine.dll"      # <--this is in-file
        "${CMAKE_CURRENT_SOURCE_DIR}/../data/KrumbEngine.dll")
add_custom_command(TARGET KrumbEngine POST_BUILD        # Adds a post-build event to MyTest
    COMMAND ${CMAKE_COMMAND} -E copy_if_different  # which executes "cmake - E copy_if_different..."
        "${CMAKE_CURRENT_BINARY_DIR}/../bin/Debug/glewd.dll"      # <--this is in-file
        "${CMAKE_CURRENT_SOURCE_DIR}/../data/glewd.dll") 
endif()