#include "race_data.h"
#include "raylib.h"
#include "raygui.h"
#include <string.h>

RaceInfo raceDatabase[] = {
    {
        "Dragonborn",
        "static/DbornRace.png",
        "Born of dragons, as their name proclaims, the dragonborn walk proudly..."
    },
    {
        "Elf",
        "static/ElfRace.png",
        "Elves are a magical people of otherworldly grace..."
    },
    {
        "Dwarf",
        "static/DwarfRace.png",
        "Bold and hardy, dwarves are known as skilled warriors..."
    },
    // Finish
};

const int NUM_RACES = sizeof(raceDatabase) / sizeof(raceDatabase[0]);

void LoadRaceTextures(void) {
    for (int i = 0; i < NUM_RACES; i++) {
        Image img = LoadImage(raceDatabase[i].imagePath);
        raceDatabase[i].texture = LoadTextureFromImage(img);
        UnloadImage(img);
    }
}

void UnloadRaceTextures(void) {
    for (int i = 0; i < NUM_RACES; i++) {
        UnloadTexture(raceDatabase[i].texture);
    }
}

RaceInfo* GetRaceInfo(const char *name) {
    for (int i = 0; i < NUM_RACES; i++) {
        if (strcmp(raceDatabase[i].name, name) == 0) {
            return &raceDatabase[i];
        }
    }
    return NULL;
}

