#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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

int main(void) 
{
	int stats = 6, die = 4, sum = 0;
	int sumStats[stats];
	int rollStats[die];
	srand(time(NULL));
	
	
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

	for (int i = 0; i < stats; i++) {
		printf("%d\n", sumStats[i]);
	}

	return 0;
}
