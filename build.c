#include "stdio.h"
#include "stdlib.h"

int main()
{
    #ifdef __APPLE__
    char* command = "clang -x objective-c ./main.c -x none -o window ./build_deps/raylib-6.0_macos/lib/libraylib.6.0.0.dylib -Wl,-rpath,@executable_path/build_deps/raylib-6.0_macos/lib/ -framework Cocoa -framework OpenGL -framework CoreVideo";
    #endif
    system(command);
}