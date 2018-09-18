cmake_minimum_required(VERSION 3.7)
project(delaunay)

SET(CMAKE_BUILD_TYPE_INIT "Release")
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")
set(SOURCE_FILES cpp/main.cpp)

include_directories(
        /emscripten/
        /emscripten/emscripten/incoming/system/include
        lib/eigen
)

add_executable(delaunay ${SOURCE_FILES})

set_target_properties(delaunay PROPERTIES LINK_FLAGS " -s NO_EXIT_RUNTIME=1 -s WASM=1 -O3 -s MODULARIZE=1 -s EXPORT_NAME=DelaunayModule -s EXTRA_EXPORTED_RUNTIME_METHODS=[ccall,cwrap] --llvm-lto 3")


file(INSTALL web/. DESTINATION .) # only runs when refreshing cmake
