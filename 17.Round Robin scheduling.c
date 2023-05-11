#include <stdio.h>
#define MAX_PROCESSES 3
#define TIME_QUANTUM 4
void calculateWaitingTime(int burstTime[], int n, int waitingTime[]) 
{
    int i,remainingTime[MAX_PROCESSES];
    for (i = 0; i < n; i++) 
	{
        remainingTime[i] = burstTime[i];
    }
    int currentTime = 0;
    while (1) 
	{
        int i,allProcessesComplete = 1;
        for (i = 0; i < n; i++) 
		{
            if (remainingTime[i] > 0) 
			{
                allProcessesComplete = 0;
                if (remainingTime[i] > TIME_QUANTUM) 
				{
                    currentTime += TIME_QUANTUM;
                    remainingTime[i] -= TIME_QUANTUM;
                } 
				else 
				{
                    currentTime += remainingTime[i];
                    waitingTime[i] = currentTime - burstTime[i];
                    remainingTime[i] = 0;
                }
            }
        }
        if (allProcessesComplete)
            break;
    }
}
void calculateTurnaroundTime(int burstTime[], int n, int waitingTime[], int turnaroundTime[]) 
{
	int i;
    for (i = 0; i < n; i++) 
	{
        turnaroundTime[i] = burstTime[i] + waitingTime[i];
    }
}
void calculateAverageTimes(int burstTime[], int n) 
{
    int waitingTime[MAX_PROCESSES] = {0};
    int turnaroundTime[MAX_PROCESSES] = {0};
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;
    int i;
    calculateWaitingTime(burstTime, n, waitingTime);
    calculateTurnaroundTime(burstTime, n, waitingTime, turnaroundTime);
    for (i = 0; i < n; i++) 
	{
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }
    float averageWaitingTime = (float)totalWaitingTime / n;
    float averageTurnaroundTime = (float)totalTurnaroundTime / n;
    printf("Average Waiting Time: %.2f\n", averageWaitingTime);
    printf("Average Turnaround Time: %.2f\n", averageTurnaroundTime);
}
int main() 
{
    int burstTime[MAX_PROCESSES] = {24, 3, 3};
    int n = sizeof(burstTime) / sizeof(burstTime[0]);
    calculateAverageTimes(burstTime, n);
    return 0;
}
