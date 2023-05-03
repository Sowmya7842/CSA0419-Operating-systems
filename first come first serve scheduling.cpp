#include <stdio.h>
#define N 3
int main()
{
	int i;
    int pid[] = {0, 1, 2};        
    int burst_time[] = {2, 4, 8}; 
    int arrival_time[] = {0, 0, 0}; 
    int waiting_time[N], turnaround_time[N];
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    waiting_time[0] = 0;
    for (i = 1; i < N; i++) 
	{
        waiting_time[i] = waiting_time[i-1] + burst_time[i-1];
    }
    for (i = 0; i < N; i++) 
	{
        turnaround_time[i] = waiting_time[i] + burst_time[i];
    }
    for (i = 0; i < N; i++) 
	{
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    avg_waiting_time /= N;
    avg_turnaround_time /= N;
    printf("Process\tBurst time\tArrival time\tWaiting time\tTurnaround time\n");
    for (i = 0; i < N; i++) 
	{
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], burst_time[i], arrival_time[i], waiting_time[i], turnaround_time[i]);
    }
    printf("Average waiting time: %.2f\n", avg_waiting_time);
    printf("Average turnaround time: %.2f\n", avg_turnaround_time);
    return 0;
}


