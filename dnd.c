#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

int main(void)
{
	int operation, stats = 6, die = 4, sum = 0;
	int sumStats[stats];
	int rollStats[die];
	char ch;
	srand(time(NULL));

	printf("\t\t\tWelcome to the DnD(5e) character Creator!\n\t\t\tfollow the instructions to create your character.\n");

	printf("First choose your race.\n");
	printf("1. Dragonborn.\n2. Dwarf.\n3. Elf.\n4. Goliath.\n5. Halfling.\n6. Human.\n7. Orc.\n8. Tiefling.\n");

	scanf("%d", &operation);

	//Bookmark
	switch (operation) {
		case 1:
			struct Player dragonborn = {"Dragonborn", "Humanoid", "Medium", 30,}; 
			printf("You have chosen Dragonborn.\nWould you like to see this races description?(Y/N)\n");
			scanf(" %c", &ch);
			if (ch == 'Y' || ch  == 'y') {
				printf("BIO\n");
				break;
			} 
			if (ch == 'N' || ch == 'n') {
				
				printf("As a Dragonborn, you have these special traits.\n|Breath Weapon|\n|Damage Resistance|\n|Darkvision|\n|Draconic Flight(lvl5+)|\n");
				printf("Draconic Ancestry:\nYour lineage stems from a dragon progenitor.\nChoose the kind of dragon from the Draconic Ancestors table.\nYour choice affects your Breath Weapon and Damage Resistance traits as well as your appearance.\n");
				printf("|Dragon : Damage Type|\n1.|Black : Acid|\t2.|Blue : Lightning|\t3.|Brass : Fire|\n4.|Bronze : Lightning|\t5.|Copper : Acid|\t6.|Gold : Fire|\n7.|Green : Poison|\t8.|Red : Fire|\t\t9.|Silver : Cold|\n10.|White : Cold|\n");
				scanf("%d", &operation);
				switch (operation) {
					case 1:
						strcpy(dragonborn.DragonType, "Black");
						strcpy(dragonborn.DamageType, "Acid");
						printf("You're a %s %s now! you're a %s type creature of %s size with a speed of %d and resistance to %s\n", dragonborn.DragonType, dragonborn.Race, dragonborn.CreatureType, dragonborn.Size, dragonborn.Speed, dragonborn.DamageType);
						break;
					case 2:
						strcpy(dragonborn.DragonType, "Blue");
						strcpy(dragonborn.DamageType, "Lightning");
						printf("You're a %s %s now! you're a %s type creature of %s size with a speed of %d and resistance to %s\n", dragonborn.DragonType, dragonborn.Race, dragonborn.CreatureType, dragonborn.Size, dragonborn.Speed, dragonborn.DamageType);
						break;
					case 3:
						strcpy(dragonborn.DragonType, "Brass");
						strcpy(dragonborn.DamageType, "Fire");
						printf("You're a %s %s now! you're a %s type creature of %s size with a speed of %d and resistance to %s\n", dragonborn.DragonType, dragonborn.Race, dragonborn.CreatureType, dragonborn.Size, dragonborn.Speed, dragonborn.DamageType);
						break;
					case 4:
						strcpy(dragonborn.DragonType, "Bronze");
						strcpy(dragonborn.DamageType, "Lightning");
						printf("You're a %s %s now! you're a %s type creature of %s size with a speed of %d and resistance to %s\n", dragonborn.DragonType, dragonborn.Race, dragonborn.CreatureType, dragonborn.Size, dragonborn.Speed, dragonborn.DamageType);
						break;
					case 5:
						strcpy(dragonborn.DragonType, "Copper");
						strcpy(dragonborn.DamageType, "Acid");
						printf("You're a %s %s now! you're a %s type creature of %s size with a speed of %d and resistance to %s\n", dragonborn.DragonType, dragonborn.Race, dragonborn.CreatureType, dragonborn.Size, dragonborn.Speed, dragonborn.DamageType);
						break;
					case 6:
						strcpy(dragonborn.DragonType, "Gold");
						strcpy(dragonborn.DamageType, "Fire");
						printf("You're a %s %s now! you're a %s type creature of %s size with a speed of %d and resistance to %s\n", dragonborn.DragonType, dragonborn.Race, dragonborn.CreatureType, dragonborn.Size, dragonborn.Speed, dragonborn.DamageType);
						break;
					case 7:
						strcpy(dragonborn.DragonType, "Green");
						strcpy(dragonborn.DamageType, "Poison");
						printf("You're a %s %s now! you're a %s type creature of %s size with a speed of %d and resistance to %s\n", dragonborn.DragonType, dragonborn.Race, dragonborn.CreatureType, dragonborn.Size, dragonborn.Speed, dragonborn.DamageType);
						break;
					case 8:
						strcpy(dragonborn.DragonType, "Red");
						strcpy(dragonborn.DamageType, "Fire");
						printf("You're a %s %s now! you're a %s type creature of %s size with a speed of %d and resistance to %s\n", dragonborn.DragonType, dragonborn.Race, dragonborn.CreatureType, dragonborn.Size, dragonborn.Speed, dragonborn.DamageType);
						break;
					case 9:
						strcpy(dragonborn.DragonType, "Silver");
						strcpy(dragonborn.DamageType, "Cold");
						printf("You're a %s %s now! you're a %s type creature of %s size with a speed of %d and resistance to %s\n", dragonborn.DragonType, dragonborn.Race, dragonborn.CreatureType, dragonborn.Size, dragonborn.Speed, dragonborn.DamageType);
						break;
						case 10:
						strcpy(dragonborn.DragonType, "White");
						strcpy(dragonborn.DamageType, "cold");
						printf("You're a %s %s now! you're a %s type creature of %s size with a speed of %d and resistance to %s\n", dragonborn.DragonType, dragonborn.Race, dragonborn.CreatureType, dragonborn.Size, dragonborn.Speed, dragonborn.DamageType);
						break;

				}
			}
			//end of case1
			break;
					case 2:
						struct Player dwarf = {"Dwarf", "Humanoid", "Medium", 30};
						printf("You have chosen Dwarf.\nWould you like to see this races description?(Y/N)\n");
						scanf("%c", &ch);
						if (ch == 'Y' || ch == 'y') {
							printf("BIO\n");
							break;
						}
						if (ch == 'N' || ch == 'n') {
							printf("As a Dwarf, you have these special traits.\n|Darkvision|\t|Dwarven Resilience|\t|Dwarven Toughness|\n|Stonecunning|\n");
							printf("You're a %s now! you're a %s type creature of %s size with a speed of %d.\n", dwarf.Race, dwarf.CreatureType, dwarf.Size, dwarf.Speed);
							break;
						} else {
							printf("Invalid Input");
						}
						break;
								
	}
	


//stat rolling
	for (int i = 0; i < stats; i++) {
		roll_dice(rollStats, die);
		find_Min(rollStats, &die);
		sum = 0;
		for (int j = 0; j < die; j++) {
			sum += rollStats[j];
		}
		sumStats[i] = sum;
		die = 4;
	}
	
	printf("Calculated ability scores:\n");
	for (int i = 0; i < stats; i++) {
		printf("%d\n", sumStats[i]);
	}

	return 0;
}
