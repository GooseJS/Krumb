project(Krumb)
cmake_minimum_required(VERSION 3.11)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

set(GLM_QUIET ON)
option(GLM_QUIET ON)

set(GLM_TEST_ENABLE OFF)
option(GLM_TEST_ENABLE OFF)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(lib/glfw)
add_subdirectory(lib/glew)

add_subdirectory(lib/glm)
add_subdirectory(lib/spdlog)

add_subdirectory(lib/json)

add_definitions(-DKMB_PLATFORM_WINDOWS)

add_subdirectory(Engine)
add_subdirectory(Krumb)
