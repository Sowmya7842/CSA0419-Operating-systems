#include <stdio.h>
#include <stdbool.h>
#define NUM_PARTITIONS 4
#define NUM_PROCESSES 5
struct MemoryPartition 
{
    int size;
    bool allocated;
};
struct Process 
{
    int size;
    bool allocated;
};
void firstFit(struct MemoryPartition memoryPartitions[], int numPartitions, struct Process processes[], int numProcesses) {
    int i, j;
    for (i = 0; i < numProcesses; i++) 
	{
        for (j = 0; j < numPartitions; j++) {
            if (memoryPartitions[j].size >= processes[i].size && !memoryPartitions[j].allocated) 
			{
                memoryPartitions[j].allocated = true;
                processes[i].allocated = true;
                printf("Process of size %d KB is allocated to partition %d.\n", processes[i].size, j + 1);
                break;
            }
        }
        if (!processes[i].allocated) 
		{
            printf("Process of size %d KB cannot be allocated.\n", processes[i].size);
        }
    }
}
int main() 
{
    struct MemoryPartition memoryPartitions[NUM_PARTITIONS] = {
        {40, false},
        {10, false},
        {30, false},
        {60, false}
    };
    struct Process processes[NUM_PROCESSES] = {
        {100, false},
        {50, false},
        {30, false},
        {120, false},
        {35, false}
    };
    firstFit(memoryPartitions, NUM_PARTITIONS, processes, NUM_PROCESSES);
    return 0;
}
