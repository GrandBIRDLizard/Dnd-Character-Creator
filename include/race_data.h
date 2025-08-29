#ifndef RACE_DATA_H
#define RACE_DATA_H

#include "raylib.h"

typedef struct {
    const char *name;
    const char *imagePath;
    const char *description;
	const char *Traitdesc1;
	const char *Traitdesc2;
	const char *Traitdesc3;
	const char *Traitdesc4;
    Texture2D texture;
} RaceInfo;

extern RaceInfo raceDatabase[];
extern const int NUM_RACES;

void LoadRaceTextures(void);
void UnloadRaceTextures(void);
RaceInfo* GetRaceInfo(const char *name);

#endif

