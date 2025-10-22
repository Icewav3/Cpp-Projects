#include <iostream>

// Add raylib header
#include "raylib.h"

int main() {
    // Initialize the window
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib empty window example");

    SetTargetFPS(60);   // Set our game to run at 60 frames-per-second

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Hello, world!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();  // Close the window and OpenGL context

    return 0;
}