project(KrumbGame)

set(KRUMB_GAME_SRC      "src/Krumb.cpp"
			"src/Krumb/world/Block.cpp"
			"src/Krumb/world/Block.h"
			"src/Krumb/world/Chunk.cpp"
			"src/Krumb/world/Chunk.h"
			"src/Krumb/world/WorldDefines.h"
			"src/Krumb/filesystem/WorldIO.h"
			"src/Krumb/filesystem/WorldIO.cpp"
                        "src/Krumb/world/World.h"
			"src/Krumb/world/World.cpp"
                        "src/Krumb/render/ChunkMesh.h"
                        "src/Krumb/render/ChunkMeshBuilder.h"
                        "src/Krumb/render/ChunkMeshBuilder.cpp"
                        "src/Krumb/render/WorldRenderer.h"
                        "src/Krumb/render/WorldRenderer.cpp"
                        "src/Krumb/entity/Entity.h"
                        "src/Krumb/entity/Player.h"
                        "src/Krumb/entity/Player.cpp"
                        "src/Krumb/render/Camera.h"
                        "src/Krumb/render/Camera.cpp")

add_executable(KrumbGame "${KRUMB_GAME_SRC}")
target_include_directories(KrumbGame PUBLIC KrumbEngine "../lib/json/single_include" "src" "../lib/glm")
target_link_libraries(KrumbGame PUBLIC KrumbEngine libglew_shared)

set_property(TARGET KrumbGame PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/data")
set_property(TARGET KrumbGame PROPERTY CXX_STANDARD 17)
