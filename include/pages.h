#ifndef PAGES_H
#define PAGES_H

#include "player.h"

typedef enum {
    PAGE1,
    PAGE2,
    PAGE3,
} PageNum;

PageNum RaceSelect(struct Player *player);
PageNum InfoPage(struct Player *player);
PageNum SubRace(struct Player *player);

#endif

