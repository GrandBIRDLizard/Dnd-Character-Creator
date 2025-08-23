#include "raylib.h"
#include "raygui.h"
#include "race_data.h"
#include "pages.h"
#include <string.h>

PageNum RaceSelect(struct Player *player) {
    static int optionSelected = 0;
	static int lineageSelected = 0;
	static int typeSelected = 0;
    static bool dropOptionsActive = false; 
	static bool dropTypesActive = false;
	static bool dropLineageActive = false;
    const char *raceOptions = "Dragonborn;Dwarf;Elf;Goliath;Halfling;Human;Orc;Tiefling";
	const char *dragonTypes = "Black;Blue;Brass;Bronze;Copper;Gold;Green;Red;Silver;White";
	const char *elvenLineages = "Drow;High Elf;Wood Elf"; 

    GuiLabel((Rectangle){10, 40, 200, 20}, "Choose Option:");

    if (GuiButton((Rectangle){680, 750, 100, 30}, "Next")) {
        return PAGE2;
    }

    if (GuiButton((Rectangle){10, 120, 100, 30}, "Confirm Race")) {
        switch (optionSelected) {
            case 0: strcpy(player->Race, "Dragonborn"); break;
            case 1: strcpy(player->Race, "Dwarf"); break;
            case 2: strcpy(player->Race, "Elf"); break;
            case 3: strcpy(player->Race, "Goliath"); break;
            case 4: strcpy(player->Race, "Halfling"); break;
            case 5: strcpy(player->Race, "Human"); break;
            case 6: strcpy(player->Race, "Orc"); break;
            case 7: strcpy(player->Race, "Tiefling"); break;
        }
	
    }
	
	if (strcmp(player->Race, "Dragonborn") == 0) {
		DrawText(TextFormat("Your lineage stems from a dragon progenitor. Choose the kind of dragon from the Draconic Ancestors table.\nYour choice affects your Breath Weapon and Damage Resistance traits as well as your appearance."), 10, 300, 14, RAYWHITE);
		GuiLabel((Rectangle){10, 350, 200, 20}, "Choose Type:");
		if (GuiButton((Rectangle){10, 430, 100, 30}, "Confirm Type ")) { 
			switch (typeSelected) {
				case 0: 
					strcpy(player->DragonType, "Black");
					strcpy(player->DamageType, "Acid");
					break;
				case 1: 
					strcpy(player->DragonType, "Blue");
					strcpy(player->DamageType, "Lightning");
					break;
				case 2: 
					strcpy(player->DragonType, "Brass");
					strcpy(player->DamageType, "Fire");
					break;
				case 3: 
					strcpy(player->DragonType, "Bronze");
					strcpy(player->DamageType, "Lightning");
					break;
				case 4: 
					strcpy(player->DragonType, "Copper");
					strcpy(player->DamageType, "Acid");
					break;
				case 5: 
					strcpy(player->DragonType, "Gold");
					strcpy(player->DamageType, "Fire");
					break;
				case 6: 
					strcpy(player->DragonType, "Green");
					strcpy(player->DamageType, "Poison");
					break;
				case 7: 
					strcpy(player->DragonType, "Red");
					strcpy(player->DamageType, "Fire");
					break;
				case 8: 
					strcpy(player->DragonType, "Silver");
					strcpy(player->DamageType, "Cold");
					break;
				case 9: 
					strcpy(player->DragonType, "White");
					strcpy(player->DamageType, "Cold");
					break;
			}
		}
	DrawText(TextFormat("Type selected: %s", player->DragonType), 10, 470, 20, RAYWHITE);

	DrawText(TextFormat("Damage type: %s", player->DamageType), 10, 495, 20, RAYWHITE);

	if (GuiDropdownBox((Rectangle){10, 380, 200, 30}, dragonTypes, &typeSelected, dropTypesActive)) {
		dropTypesActive = false;
	}
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) &&
		CheckCollisionPointRec(GetMousePosition(), (Rectangle){10, 380, 200, 30})) {
		dropTypesActive = !dropTypesActive;
	}	
	}

	if (strcmp(player->Race, "Elf") == 0) {
		DrawText(TextFormat("You are part of a lineage that grants you supernatural abilities. Choose a lineage from the Elven Lineages table. You gain the level 1 benefit of that lineage."), 10, 300, 14, RAYWHITE);
		GuiLabel((Rectangle){10, 350, 200, 20}, "Choose Lineage:");
		if (GuiButton((Rectangle){10, 430, 100, 30}, "Confirm Lineage ")) {
			switch (lineageSelected) {
				case 0: strcpy(player->Lineage, "Drow"); break;
				case 1: strcpy(player->Lineage, "High Elf"); break;
				case 2: strcpy(player->Lineage, "Wood Elf"); break;
			}
		}
	DrawText(TextFormat("Lineage Selected: %s", player->Lineage), 10, 470, 20, RAYWHITE);

	if (GuiDropdownBox((Rectangle){10, 380, 200, 30}, elvenLineages, &lineageSelected, dropLineageActive)) {
		dropLineageActive = false;
	}
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) &&
		CheckCollisionPointRec(GetMousePosition(), (Rectangle){10, 380, 200, 30})) {
		dropLineageActive = !dropLineageActive;
	}
	}


    DrawText(TextFormat("Option selected: %s", player->Race), 10, 160, 20, RAYWHITE);

    if (GuiDropdownBox((Rectangle){10, 70, 200, 30}, raceOptions, &optionSelected, dropOptionsActive)) {
        dropOptionsActive = false;
    }
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) &&
        CheckCollisionPointRec(GetMousePosition(), (Rectangle){10, 70, 200, 30})) {
        dropOptionsActive = !dropOptionsActive;
    }

    return PAGE1;
}

