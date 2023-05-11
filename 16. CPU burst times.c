#include <stdio.h>
#define MAX_PROCESSES 3
void calculateWaitingTime(int burstTime[], int n, int waitingTime[]) 
{
	int i;
    waitingTime[0] = 0; 
    for (i = 1; i < n; i++) 
	{
        waitingTime[i] = burstTime[i - 1] + waitingTime[i - 1];
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
	int i;
    int waitingTime[MAX_PROCESSES] = {0};
    int turnaroundTime[MAX_PROCESSES] = {0};
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;
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
    int burstTime[MAX_PROCESSES] = {10, 15, 25};
    int n = sizeof(burstTime) / sizeof(burstTime[0]);
    calculateAverageTimes(burstTime, n);
    return 0;
}
