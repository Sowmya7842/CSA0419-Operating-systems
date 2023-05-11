#include <stdio.h>
#define MAX_PARTITIONS 6
#define MAX_PROCESSES 5
void bestFit(int partitions[], int numPartitions, int processes[], int numProcesses) 
{
    int allocation[MAX_PROCESSES];
    int i, j;
    for (i = 0; i < numProcesses; i++) 
	{
        int bestFitIdx = -1;

        for (j = 0; j < numPartitions; j++) 
		{
            if (partitions[j] >= processes[i]) 
			{
                if (bestFitIdx == -1 || partitions[j] < partitions[bestFitIdx]) 
				{
                    bestFitIdx = j;
                }
            }
        }
        if (bestFitIdx != -1) 
		{
            allocation[i] = bestFitIdx;
            partitions[bestFitIdx] -= processes[i];
        }
		else 
		{
            allocation[i] = -1;
        }
    }
    printf("Process\tProcess Size\tPartition Index\n");
    for (i = 0; i < numProcesses; i++) 
	{
        printf("%d\t%d KB\t\t", i + 1, processes[i]);
        if (allocation[i] != -1) 
		{
            printf("%d\n", allocation[i]);
        } 
		else 
		{
            printf("Not Allocated\n");
        }
    }
}
int main() 
{
	int i;
    int partitions[MAX_PARTITIONS] = {300, 600, 350, 200, 750, 125};
    int processes[MAX_PROCESSES] = {115, 500, 358, 200, 375};
    printf("Memory Partitions:\n");
    for ( i = 0; i < MAX_PARTITIONS; i++) 
	{
        printf("%dKB, ", partitions[i]);
    }
    printf("\n\n");
    printf("Process Sizes:\n");
    for (i = 0; i < MAX_PROCESSES; i++) 
	{
        printf("%dKB, ", processes[i]);
    }
    printf("\n\n");
    bestFit(partitions, MAX_PARTITIONS, processes, MAX_PROCESSES);
    return 0;
}
