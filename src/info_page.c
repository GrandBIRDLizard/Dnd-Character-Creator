#include <stdio.h> 
#include "raylib.h"
#include "raygui.h"
#include "pages.h"
#include "race_data.h"

extern const int screenWidth;
extern const int screenHeight;

PageNum InfoPage(struct Player *player) {
	RaceInfo *info = GetRaceInfo(player->Race);
	if (info != NULL) {
		DrawTexture(info->texture, screenWidth/2 - info->texture.width/2,
		                      screenHeight/2 - info->texture.height/2, WHITE);

	    DrawRectangle(25, 40, 750, 750, (Color){80,80,80,175});
		DrawText("Race Info Page", 25, 40, 20, RAYWHITE);
		DrawText(TextFormat("Current Race: %s", player->Race), 25, 80, 30, YELLOW);
		DrawText(info->description, 30, 180, 18, RAYWHITE);
	} else {
		DrawText("Unknown race", 30, 80, 30, RED);
	}

	DrawLine(25, 420, 775, 420, RAYWHITE);

    if (GuiButton((Rectangle){25, 120, 100, 30}, "Back")) {
        return PAGE1;
    }
	if (GuiButton((Rectangle){220, 120, 100, 30}, "Next")) {
		return PAGE3;
	}

    return PAGE2;
}

