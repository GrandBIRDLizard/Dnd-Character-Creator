#include <stdio.h> 
#include <stdlib.h>
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
	int ch, operation, stats = 6, die = 4, sum = 0;
	int sumStats[stats];
	int rollStats[die]; 
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
			ch = getchar();
			if (getchar() == 'Y') {
				printf("BIO\n");
				break;
			} else {
				printf("You're a %s now! you're a %s type creature of %s size with a speed of %d\n", character.Race, character.CreatureType, character.Size, character.Speed);
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
