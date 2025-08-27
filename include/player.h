#ifndef PLAYER_H
#define PLAYER_H

struct Player {
    char Race[12];
    char CreatureType[12];
    char Size[20];
    int Speed;
	int Darkvision;
	//Dragonborn
    char DragonType[8];
    char DamageType[10];
	//Elf & Goliath
    char Lineage[14];
	char LineageTrait[18];
    char GiantType[12];
	char GiantBoon[16];
	//Tiefling
    char Legacy[10];
	char LegacyCantrip[14];
    char Name[35];
};

#endif
