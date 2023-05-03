#include <stdio.h>
#define MAX_PROCESSES 5
#define MAX_RESOURCES 3
int main()
{
	int i,j;
    int allocation[MAX_PROCESSES][MAX_RESOURCES] = {{1, 1, 2}, {2, 1, 2}, {3, 0, 1}, {0, 2, 0}, {1, 1, 2}};
    int max[MAX_PROCESSES][MAX_RESOURCES] = {{5, 4, 4}, {4, 3, 3}, {9, 1, 3}, {8, 6, 4}, {2, 2, 3}};
    int available[MAX_RESOURCES] = {3, 2, 1};
    int need[MAX_PROCESSES][MAX_RESOURCES];
    for (i = 0; i < MAX_PROCESSES; i++) 
	{
        for (j = 0; j < MAX_RESOURCES; j++) 
		{
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    printf("Need matrix:\n");
    for (i = 0; i < MAX_PROCESSES; i++) 
	{
        printf("P%d: ", i);
        for (j = 0; j < MAX_RESOURCES; j++) 
		{
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
    return 0;
}

