#include <stdio.h>
void calculateWaitingTime(int processes[], int n, int burstTime[], int waitingTime[]) 
{
	int i;
    int remainingTime[n];
    for (i = 0; i < n; i++) 
	{
        remainingTime[i] = burstTime[i];
    }
    int complete = 0;
    int currentTime = 0;
    int shortest = 0;
    int minTime = 9999;
    int check = 0;
    while (complete != n) 
	{
        for (i = 0; i < n; i++) 
		{
            if ((processes[i] <= currentTime) && (remainingTime[i] < minTime) && (remainingTime[i] > 0)) 
			{
                minTime = remainingTime[i];
                shortest = i;
                check = 1;
            }
        }
        if (check == 0) 
		{
            currentTime++;
            continue;
        }
        remainingTime[shortest]--;
        minTime = remainingTime[shortest];
        if (minTime == 0)
            minTime = 9999;
        if (remainingTime[shortest] == 0) 
		{
            complete++;
            check = 0;
            int finishTime = currentTime + 1;
            waitingTime[shortest] = finishTime - burstTime[shortest] - processes[shortest];
            if (waitingTime[shortest] < 0)
                waitingTime[shortest] = 0;
        }
        currentTime++;
    }
}
int i;
void calculateTurnaroundTime(int burstTime[], int waitingTime[], int n, int turnaroundTime[]) {
    for (i = 0; i < n; i++) 
	{
        turnaroundTime[i] = burstTime[i] + waitingTime[i];
    }
}
void calculateAverageTime(int processes[], int n, int burstTime[]) 
{
	int i;
    int waitingTime[n], turnaroundTime[n];
    int totalWaitingTime = 0, totalTurnaroundTime = 0;
    calculateWaitingTime(processes, n, burstTime, waitingTime);
    calculateTurnaroundTime(burstTime, waitingTime, n, turnaroundTime);
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) 
	{
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
        printf("%d\t%d\t\t%d\t\t%d\n", i, burstTime[i], waitingTime[i], turnaroundTime[i]);
    }
    printf("\nAverage Waiting Time: %.2f\n", (float)totalWaitingTime / n);
    printf("Average Turnaround Time: %.2f\n", (float)totalTurnaroundTime / n);
}
int main() 
{
    int processes[] = {0, 1, 2};
    int burstTime[] = {2, 4, 8};
    int numProcesses = sizeof(processes) / sizeof(processes[0]);
    calculateAverageTime(processes, numProcesses, burstTime);
    return 0;
}
