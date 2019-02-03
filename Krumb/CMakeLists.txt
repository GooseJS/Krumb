project(KrumbGame)

set(KRUMB_GAME_SRC "src/Krumb.cpp")

add_executable(KrumbGame "${KRUMB_GAME_SRC}")
target_include_directories(KrumbGame PUBLIC KrumbEngine)
target_link_libraries(KrumbGame PUBLIC KrumbEngine)

set_property(TARGET KrumbGame PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/data")