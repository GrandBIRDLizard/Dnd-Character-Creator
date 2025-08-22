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

	Image tavern = LoadImage("static/tavern.jpg");
	ImageResize(&tavern, 800, 800);
	Texture2D tavernbg = LoadTextureFromImage(tavern);

	LoadRaceTextures();

    struct Player player = {0};
    PageNum currentPage = PAGE1;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(DARKGRAY);


	DrawTexture(tavernbg, 800/2 - 800/2, 800/2 - 800/2, WHITE);

        switch (currentPage) {
            case PAGE1: currentPage = RaceSelect(&player); break;
            case PAGE2: currentPage = InfoPage(&player); break;
            case PAGE3: currentPage = SubRace(&player); break;
        }

        EndDrawing();
    }

	UnloadImage(tavern);
	UnloadRaceTextures();
    CloseWindow();
    return 0;
}

