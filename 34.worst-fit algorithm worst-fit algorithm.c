#include <stdio.h>
#define MAX_PARTITIONS 4
#define MAX_PROCESSES 5
void worstFit(int partitions[], int m, int processes[], int n) 
{
    int allocation[MAX_PROCESSES];
    int i, j;
    for (i = 0; i < n; i++) 
	{
        int worstFitIndex = -1;
        for (j = 0; j < m; j++) 
		{
            if (processes[i] <= partitions[j]) 
			{
                if (worstFitIndex == -1 || partitions[j] > partitions[worstFitIndex]) 
				{
                    worstFitIndex = j;
                }
            }
        }
        if (worstFitIndex != -1) 
		{
            allocation[i] = worstFitIndex;
            partitions[worstFitIndex] -= processes[i];
        }
    }
    printf("\nProcess No.\tProcess Size\tPartition No.\n");
    for (i = 0; i < n; i++) 
	{
        printf("%d\t\t%d\t\t", i + 1, processes[i]);
        if (allocation[i] != -1) 
		{
            printf("%d\n", allocation[i] + 1);
        }
		else 
		{
            printf("Not Allocated\n");
        }
    }
}
int main() 
{
    int partitions[MAX_PARTITIONS] = {40, 10, 30, 60};
    int processes[MAX_PROCESSES] = {100, 50, 30, 120, 35};
    int m = sizeof(partitions) / sizeof(partitions[0]);
    int n = sizeof(processes) / sizeof(processes[0]);
    worstFit(partitions, m, processes, n);
    return 0;
}
