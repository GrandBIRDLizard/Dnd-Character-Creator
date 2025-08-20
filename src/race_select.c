#include "raylib.h"
#include "raygui.h"
#include "race_data.h"
#include "pages.h"
#include <string.h>

PageNum RaceSelect(struct Player *player) {
    static int optionSelected = 0;
    static bool dropOptionsActive = false;
    const char *raceOptions = "Dragonborn;Dwarf;Elf;Goliath;Halfling;Human;Orc;Tiefling";

    GuiLabel((Rectangle){10, 40, 200, 20}, "Choose Option:");

    if (GuiButton((Rectangle){680, 750, 100, 30}, "Next")) {
        return PAGE2;
    }

    if (GuiButton((Rectangle){10, 120, 100, 30}, "Confirm")) {
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

    DrawText(TextFormat("Option selected: %s", player->Race), 10, 250, 20, RAYWHITE);

    if (GuiDropdownBox((Rectangle){10, 70, 200, 30}, raceOptions, &optionSelected, dropOptionsActive)) {
        dropOptionsActive = false;
    }
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) &&
        CheckCollisionPointRec(GetMousePosition(), (Rectangle){10, 70, 200, 30})) {
        dropOptionsActive = !dropOptionsActive;
    }

    return PAGE1;
}

