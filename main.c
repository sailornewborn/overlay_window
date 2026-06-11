#include "stdio.h"
#ifdef __APPLE__
#include "CoreGraphics/CoreGraphics.h"
#include "./build_deps/raylib-6.0_macos/include/raylib.h"
#import <Cocoa/Cocoa.h>
#endif
int main()
{
    int width = 800;
    int height = 600;
#ifdef __APPLE__
    CGDirectDisplayID main_display = CGMainDisplayID();
    CGDisplayModeRef mode = CGDisplayCopyDisplayMode(main_display);
    width = (int)CGDisplayModeGetWidth(mode);
    height = (int)CGDisplayModeGetHeight(mode);
    SetConfigFlags(
        FLAG_WINDOW_TOPMOST |
        FLAG_WINDOW_TRANSPARENT);
#endif

    InitWindow(width, height, "Window Overlay");

#ifdef __APPLE__
    NSWindow *glfwWindow = (NSWindow *)GetWindowHandle();
    [glfwWindow setIgnoresMouseEvents:YES];
    SetWindowState(FLAG_WINDOW_UNDECORATED);
    SetWindowPosition(0, 0);
#endif
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLANK);
        DrawFPS(10, 100);
        EndDrawing();
    }
    CloseWindow();
}