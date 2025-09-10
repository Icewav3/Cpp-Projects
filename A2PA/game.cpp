#include "game.hpp"
#include <raylib.h>

int main() {
    // Initialize raylib window
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Raylib Game Window");
    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose()) {
        // Update game logic here

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello Raylib!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    // Clean up
    CloseWindow();

    return 0;
}
