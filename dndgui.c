#include "raylib.h"
#include <string.h>
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "style_amber.h"

void roll_dice(int rollVal[], int dice)
{
	for (int i = 0; i < dice; i++) {
		rollVal[i] = (rand() % 6) + 1;
	}
}

void find_Min(int rollVal[], int *dice)
{
		int idxMin = 0;
		for (int i = 1; i < *dice; i++) {
			if (rollVal[i] < rollVal[idxMin]) {
				idxMin = i;
			}
		}
		for (int i = idxMin; i < *dice - 1; i++) {
			rollVal[i] = rollVal[i + 1];
		}
		(*dice)--;
}

struct Player {
	//Universal
	char Race[12];
	char CreatureType[12];
	char Size[20];
	int Speed;
	//Dragonborn
	char DragonType[8];
	char DamageType[10];
	//Elf & Gnome
	char Lineage[14];
	char GiantType[12];
	//Tiefling
	char Legacy[10];
	char Name[35];
};

typedef enum {
	PAGE1,
	PAGE2,
	PAGE3,
} PageNum;

PageNum RaceSelect(void);
PageNum RaceInfo(void);
PageNum SubRace(void);

//Race Globals
static int optionSelected = 0;
static bool dropOptionsActive = false;
static char Race[12] = "";
const char *raceOptions = "Dragonborn;Dwarf;Elf;Goliath;Halfling;Human;Orc;Tiefling";
//FINISH STRUCT FUNCTION PASSING!!!
PageNum RaceSelect(void) 
	{
		GuiLabel((Rectangle){10, 40, 200, 20}, "Choose Option:");
			
		if (GuiButton((Rectangle){10, 120, 100, 30}, "Confirm")) {
			switch (optionSelected) {
				case 0: strcpy(Race, "Dragonborn"); break;
				case 1: strcpy(Race, "Dwarf"); break;
				case 2: strcpy(Race, "Elf"); break;
				case 3: strcpy(Race, "Goliath"); break;
				case 4: strcpy(Race, "Halfling"); break;
				case 5: strcpy(Race, "Human"); break;
				case 6: strcpy(Race, "Orc"); break;
				case 7: strcpy(Race, "Tiefling"); break;
			}
		}
			DrawText(TextFormat("Option selected: %s", Race), 10, 250, 20, RAYWHITE);

			if (GuiDropdownBox((Rectangle){10, 70, 200, 30}, raceOptions, &optionSelected, dropOptionsActive)) {
					dropOptionsActive = false;
		}
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) &&
				CheckCollisionPointRec(GetMousePosition(), (Rectangle){10, 70, 200, 30})) {
				dropOptionsActive = !dropOptionsActive;
			}
		return PAGE1;
	}

PageNum RaceInfo() {
    DrawText("Race Info Page (todo)", 10, 40, 20, RAYWHITE);
	DrawText(TextFormat("Current Race: %s", player->Race), 10, 80, 20, YELLOW);

	if (GuiButton((Rectangle){10, 120, 100, 30}, "Back")) {
		return PAGE1;
	}

    return PAGE2;
}

PageNum SubRace(void) {
    DrawText("SubRace Page (todo)", 10, 40, 20, RAYWHITE);
    return PAGE3;
}

int main(void)
{
	InitWindow(800, 800, "RayWin");
	GuiLoadStyleAmber();
	SetTargetFPS(60);
	PageNum currentPage = PAGE1;

	struct Player player = {0};	

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(DARKGRAY);

		switch (currentPage) {
			case PAGE1: currentPage = RaceSelect(); break;
			case PAGE2: currentPage = RaceInfo(); break;
			case PAGE3: currentPage = SubRace(); break;
        }
		
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
