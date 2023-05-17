#include <stdio.h>
#define MAX_PROCESSES 3
struct Process 
{
    int burstTime;
    int priority;
};
void calculateAverageTimes(struct Process processes[], int n) 
{
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;
    int i;
    int currentTime = 0;
    for (i = 0; i < n; i++) 
	{
        int j, minPriority = 9999, minPriorityIndex = -1;
        for (j = 0; j < n; j++) 
		{
            if (processes[j].burstTime > 0 && processes[j].priority < minPriority) 
			{
                minPriority = processes[j].priority;
                minPriorityIndex = j;
            }
        }
        if (minPriorityIndex != -1) 
		{
            int burstTime = processes[minPriorityIndex].burstTime;
            processes[minPriorityIndex].burstTime = 0;
            int waitingTime = currentTime;
            int turnaroundTime = currentTime + burstTime;
            totalWaitingTime += waitingTime;
            totalTurnaroundTime += turnaroundTime;
            currentTime += burstTime;
        }
    }
    double avgWaitingTime = (double)totalWaitingTime / n;
    double avgTurnaroundTime = (double)totalTurnaroundTime / n;
    printf("Average Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);
}
int main() 
{
    struct Process processes[MAX_PROCESSES] = 
	{
        {30, 2},
        {5, 1},
        {12, 3}
    };
    int n = sizeof(processes) / sizeof(processes[0]);
    calculateAverageTimes(processes, n);
    return 0;
}
