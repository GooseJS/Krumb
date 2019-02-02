project(KrumbEngine)

set(KRUMB_ENGINE_SRC "src/Engine/Application" "src/Engine/EntryPoint" "src/KrumbEngine")

add_library(KrumbEngine STATIC "${KRUMB_ENGINE_SRC}")