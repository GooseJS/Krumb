project(KrumbEngine)

set(KRUMB_ENGINE_SRC	"src/Engine/Application.cpp"
						"src/Engine/Application.h"
						"src/Engine/EntryPoint.h"
						"src/Engine/Logger.cpp"
						"src/Engine/Logger.h"
						"src/KrumbEngine.h")

include_directories("../lib/spdlog/include")

add_library(KrumbEngine STATIC "${KRUMB_ENGINE_SRC}")