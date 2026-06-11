#include "stdio.h"
#ifdef __APPLE__
#include "./build_deps/raylib-6.0_macos/include/raylib.h"
#import <Cocoa/Cocoa.h>
#endif
int main()
{
    SetConfigFlags(FLAG_WINDOW_UNDECORATED |
                   FLAG_WINDOW_TOPMOST |
                   FLAG_WINDOW_TRANSPARENT);
    InitWindow(GetMonitorWidth(0), GetMonitorHeight(0),"Window Overlay");
    #ifdef __APPLE__
    NSWindow* glfwWindow = (NSWindow*)GetWindowHandle();
    [glfwWindow setIgnoresMouseEvents:YES]; 
    #endif
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLANK);
        DrawFPS(10,100);
        EndDrawing();
    }
    CloseWindow();
}