project(KrumbGame)

set(KRUMB_GAME_SRC "src/Krumb.cpp")
include_directories("../Engine/src/")

add_executable(KrumbGame "${KRUMB_GAME_SRC}")
target_link_libraries(KrumbGame KrumbEngine)
