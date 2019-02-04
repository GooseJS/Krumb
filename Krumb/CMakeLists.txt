project(KrumbGame)

set(KRUMB_GAME_SRC	"src/Krumb.cpp"
					"src/Krumb/world/Block.cpp"
					"src/Krumb/world/Block.h"
					"src/Krumb/world/Chunk.cpp"
					"src/Krumb/world/Chunk.h"
					"src/Krumb/filesystem/WorldIO.h"
					"src/Krumb/filesystem/WorldIO.cpp")

add_executable(KrumbGame "${KRUMB_GAME_SRC}")
target_include_directories(KrumbGame PUBLIC KrumbEngine "../lib/json/single_include" "src")
target_link_libraries(KrumbGame PUBLIC KrumbEngine libglew_shared)

set_property(TARGET KrumbGame PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/data")