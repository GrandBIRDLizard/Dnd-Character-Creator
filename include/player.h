#ifndef PLAYER_H
#define PLAYER_H

struct Player {
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

#endif
