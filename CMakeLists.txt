cmake_minimum_required(VERSION 3.7)
project(delaunay)

SET(CMAKE_BUILD_TYPE_INIT "Release")
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")
set(SOURCE_FILES cpp/main.cpp cpp/html5.h)

include_directories(
        /emscripten/
        /emscripten/emscripten/incoming/system/include
        lib/eigen
)

# Use webgl2 and glfw3
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s USE_WEBGL2=1 -s USE_GLFW=3")

add_executable(delaunay ${SOURCE_FILES})


set_target_properties(delaunay PROPERTIES LINK_FLAGS "  -s USE_WEBGL2=1 -s USE_GLFW=3 -s NO_EXIT_RUNTIME=1 -s WASM=1 -O3 -s MODULARIZE=1 -s EXPORT_NAME=DelaunayModule -s  EXTRA_EXPORTED_RUNTIME_METHODS=[ccall,cwrap,allocateUTF8] --llvm-lto 3")
target_link_libraries(delaunay
        glfw
        ${OPENGL_LIBRARIES}
        ${OPENGL_gl_LIBRARY})

install(DIRECTORY web/ DESTINATION ${PROJECT_BINARY_DIR}) # only runs when refreshing cmake
