#include <stdio.h>
#include <stdbool.h>
#define MAX_PARTITIONS 6
#define MAX_PROCESSES 5
int partitions[MAX_PARTITIONS];
bool allocated[MAX_PARTITIONS] = {false};
void worstFit(int processSize[], int n) 
{
	int i;
    for (i = 0; i < n; i++) 
	{
        int worstFitIndex = -1;
        int worstFitSize = 0;
        int j;
        for (j = 0; j < MAX_PARTITIONS; j++) 
		{
            if (!allocated[j] && partitions[j] >= processSize[i]) 
			{
                if (worstFitIndex == -1 || partitions[j] > worstFitSize) 
				{
                    worstFitIndex = j;
                    worstFitSize = partitions[j];
                }
            }
        }
        if (worstFitIndex != -1) 
		{
            allocated[worstFitIndex] = true;
            printf("Process %d (Size: %d KB) allocated to Partition %d (Size: %d KB)\n", i + 1, processSize[i], worstFitIndex + 1, partitions[worstFitIndex]);
        } 
		else 
		{
            printf("Process %d (Size: %d KB) cannot be allocated\n", i + 1, processSize[i]);
        }
    }
}
int main() 
{
    int processSize[MAX_PROCESSES] = {115, 500, 358, 200, 375};
    int partitionSize[MAX_PARTITIONS] = {300, 600, 350, 200, 750, 125};
    int i;
	for (i = 0; i < MAX_PARTITIONS; i++) 
	{
        partitions[i] = partitionSize[i];
    }
    worstFit(processSize, MAX_PROCESSES);
    return 0;
}
