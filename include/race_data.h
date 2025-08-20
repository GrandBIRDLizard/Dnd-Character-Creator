#ifndef RACE_DATA_H
#define RACE_DATA_H

#include "raylib.h"

typedef struct {
    const char *name;
    const char *imagePath;
    const char *description;
    Texture2D texture;
} RaceInfo;

extern RaceInfo raceDatabase[];
extern const int NUM_RACES;

void LoadRaceTextures(void);
void UnloadRaceTextures(void);
RaceInfo* GetRaceInfo(const char *name);

#endif

