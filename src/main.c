#include <string.h>
#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "style_amber.h"
#include "pages.h"
#include "player.h"
#include "race_data.h"

const int screenWidth = 800;
const int screenHeight = 800;

int main(void) {
    InitWindow(screenWidth, screenHeight, "DnD GUI");
    GuiLoadStyleAmber();
    SetTargetFPS(60);

	LoadRaceTextures();

    struct Player player = {0};
    PageNum currentPage = PAGE1;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(DARKGRAY);

        switch (currentPage) {
            case PAGE1: currentPage = RaceSelect(&player); break;
            case PAGE2: currentPage = InfoPage(&player); break;
            case PAGE3: currentPage = SubRace(&player); break;
        }

        EndDrawing();
    }

	UnloadRaceTextures();
    CloseWindow();
    return 0;
}

