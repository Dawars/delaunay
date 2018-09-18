//
// Created by dawars on 2018.09.18..
//

#include <emscripten.h>
#include <string>
#include <GLES2/gl2.h>
#include <EGL/egl.h>
#include <iostream>

extern "C" {
#include "html5.h" // emscripten module
}

int main() {

    /*  EMSCRIPTEN_WEBGL_CONTEXT_HANDLE context;
      // Context configurations
      EmscriptenWebGLContextAttributes attrs;
      attrs.explicitSwapControl = 0;
      attrs.depth = 1;
      attrs.stencil = 1;
      attrs.antialias = 1;
      attrs.majorVersion = 2;
      attrs.minorVersion = 0;

      context = emscripten_webgl_create_context(0, &attrs);
      emscripten_webgl_make_context_current(context);
  */
    return 0;
}

extern "C" {

EMSCRIPTEN_KEEPALIVE
void createContext(char *id) {

    // Context configurations
    EmscriptenWebGLContextAttributes attrs;/*
    attrs.explicitSwapControl = 0;
    attrs.depth = 1;
    attrs.stencil = 1;
    attrs.antialias = 1;*/
    attrs.majorVersion = 1;
    attrs.minorVersion = 0;

    attrs.alpha = 0;
    attrs.depth = 1;
    attrs.stencil = 1;
    attrs.antialias = 1;
    attrs.premultipliedAlpha = 1;
    attrs.preserveDrawingBuffer = 0;
//    attrs.powerPreference= _powerPreference

    EMSCRIPTEN_WEBGL_CONTEXT_HANDLE context;
    std::cout << id << std::endl;
    context = emscripten_webgl_create_context(id, &attrs);
    emscripten_webgl_make_context_current(context);


    free(id);
}
}