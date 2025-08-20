#include "race_data.h"
#include "raylib.h"
#include "raygui.h"
#include <string.h>

RaceInfo raceDatabase[] = {
    {
        "Dragonborn",
        "static/DbornRace.png",
        "Born of dragons, as their name proclaims, the dragonborn walk proudly through a\n\nworld that greets them with fearful incomprehension. Shaped by draconic gods or the\ndragons themselves,\n\ndragonborn originally hatched from dragon eggs as a unique race,\n\ncombining the best attributes of dragons and humanoids. Some dragonborn are faithful\n\nservants to true dragons, others form the ranks of soldiers in great wars, and still\n\nothers find themselves adrift, with no clear calling in life."
    },
    {
        "Dwarf",
        "static/DwarfRace.png",
        "Bold and hardy, dwarves are known as skilled warriors, miners,\nand workers of stone and metal.\n\nThough they stand well under 5 feet tall, dwarves are so broad and compact that\n\nthey can weigh as much as a human standing nearly two feet taller.\n\nTheir courage and endurance are also easily a match for any of the larger folk."
    },
    {
        "Elf",
        "static/ElfRace.png",
        "Elves are a magical people of otherworldly grace,\nliving in the world but not entirely part of it.\n\nThey live in places of ethereal beauty, in the midst of ancient forests\nor in silvery spires glittering with faerie light,\nwhere soft music drifts through the air and gentle fragrances waft on the breeze.\n\nElves love nature and magic, art and artistry, music and poetry,\nand the good things of the world."
    },
	{
		"Goliath",
		"static/GoliathRace.png",
		"At the highest mountain peaks-far above the slopes where trees grow and the air is thin\nthe frigid winds howl-dwell the reclusive goliaths.\n\nFew folk can claim to have seen a goliath, and fewer still can claim friendship with one.\nGoliaths wander a bleak realm of rock, wind, and cold. Their bodies\nlook as if they are carved from mountain stone and give them great physical power.\n\nTheir spirits take after the wandering wind,\nmaking them nomads who wander from peak to peak.\n\nTheir hearts are infused with the cold regard of their frigid realm,\nleaving each goliath with the responsibility to earn a place in the tribe or die trying."
	},
	{
		"Halfling",
		"static/HalflingRace.png",
		"The comforts of home are the goals of most halflings’ lives:\na place to settle in peace and quiet, far from marauding monsters and clashing armies;\na blazing fire, generous meal and fine drink and conversation.\n\nThough some halflings live out their days in remote agricultural communities,\nothers form nomadic bands that travel constantly,\nlured by the open road and the wide horizon\nto discover the wonders of new lands and peoples.\n\nBut even these wanderers love peace, food, hearth, and home,\nthough home might be a wagon jostling along a dirt road or a raft floating downriver."
	},
	{
		"Human",
		"static/HumanRace.png",
		"In the reckonings of most worlds, humans are the youngest of the common races,\nlate to arrive on the world scene and short-lived in comparison to dwarves, elves,\nand dragons.\n\nPerhaps it is because of their shorter lives\nthey strive to achieve as much as they can in the years they are given.\n\nOr maybe they feel they have something to prove to the elder races,\nand that’s why they build their mighty empires on the foundation of conquest and trade.\n\nWhatever drives them, humans are the innovators,\nthe achievers, and the pioneers of the worlds."
	},
	{
		"Orc",
		"static/OrcRace.png",
		"Savage and fearless,\norc tribes are ever in search of elves, dwarves, and humans to destroy.\n\nMotivated by their hatred of the civilized races of the world\nand their need to satisfy the demands of their deities.\n\nThe orcs know that if they fight well and bring glory to their tribe,\nGruumsh will call them home."
	},
	{
		"Tiefling",
		"static/TieflingRace.png",
		"To be greeted with stares and whispers,\nto suffer violence and insult on the street,\nto see mistrust and fear in every eye:\n\nthis is the lot of the tiefling. And to twist the knife,\ntieflings know that this is because a pact struck generations ago\ninfused the essence of Asmodeus—overlord of the Nine Hells—into their bloodline.\n\nTheir appearance and their nature are not their fault\nbut the result of an ancient sin,\nfor which they, their children and their childrens children will always be held accountable."
	}
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

