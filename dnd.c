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
			struct Player character = {"Dragonborn", "Humanoid", "Medium", 30,}; 
			printf("You have chosen Dragonborn.\nWould you like to see this races description?(Y/N)\n");
			scanf(" %c", &ch);
			if (ch == 'Y' || ch  == 'y') {
				printf("BIO\n");
				break;
			} 
			if (ch == 'N' || ch == 'n') {
				
				printf("As a Dragonborn, you have these special traits.\n|Breath Weapon|\n|Damage Resistance|\n|Darkvision|\n|Draconic Flight(lvl5+)|\n");
				printf("Draconic Ancestry:\nYour lineage stems from a dragon progenitor.\nChoose the kind of dragon from the Draconic Ancestors table.\nYour choice affects your Breath Weapon and Damage Resistance traits as well as your appearance.\n");
				printf("|Dragon : Damage Type|\n1.|Black : Acid|\n2.|Blue : Lightning|\n3.|Brass : Fire|\n4.|Bronze : Lightning|\n5.|Copper : Acid|\n6.|Gold : Fire|\n7.|Green : Poison|\n8.|Red : Fire|\n9.|Silver : Cold|\n10.|White : Cold|\n");
				scanf("%d", &operation);
				switch (operation) {
					case 1:
						strcpy(character.DragonType, "Black");
						strcpy(character.DamageType, "Acid");
						printf("You're a %s %s now! you're a %s type creature of %s size with a speed of %d and resistance to %s\n", character.DragonType, character.Race, character.CreatureType, character.Size, character.Speed, character.DamageType);
						 
				}
				//printf("%d", operation);	
				break;
			}

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
