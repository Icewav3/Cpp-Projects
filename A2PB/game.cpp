#include "game.hpp"
#include <raylib.h>

//type in text while getting your text exploded

int main() {
    // Initialize raylib window
    constexpr int screenWidth = 800;
    constexpr int screenHeight = 450;


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
