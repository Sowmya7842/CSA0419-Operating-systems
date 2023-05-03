#include<stdio.h>
#include<stdlib.h>
struct process
{
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
    int executed;
};
int main()
{
    int num_processes, t = 0, completed = 0, min_index, min_remaining_time = 9999,i;
    float total_waiting_time = 0, total_turnaround_time = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    struct process* processes = (struct process*)malloc(num_processes * sizeof(struct process));
    for(i=0; i<num_processes; i++)
	{
        printf("\nEnter the arrival time and burst time for process P%d: ", i+1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].completion_time = 0;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
        processes[i].executed = 0;
    }
    while(completed != num_processes)
	{
        min_remaining_time = 9999;
        for(i=0; i<num_processes; i++)
		{
            if(processes[i].arrival_time <= t && processes[i].remaining_time < min_remaining_time && !processes[i].executed)
			{
                min_index = i;
                min_remaining_time = processes[i].remaining_time;
            }
        }
        processes[min_index].remaining_time--;
        t++;
        for(i=0; i<num_processes; i++)
		{
            if(processes[i].arrival_time <= t && !processes[i].executed)
			{
                if(i != min_index)
				{
                    processes[i].waiting_time++;
                }

                if(processes[i].remaining_time == 0)
				{
                    processes[i].turnaround_time = t - processes[i].arrival_time;
                    processes[i].completion_time = t;
                    total_waiting_time += processes[i].waiting_time;
                    total_turnaround_time += processes[i].turnaround_time;
                    processes[i].executed = 1;
                    completed++;
                }
            }
        }
    }

    printf("\nProcess\tWaiting Time\tTurnaround Time\n");
    for( i=0; i<num_processes; i++)
	{
        printf("P%d\t\t%d\t\t%d\n", i+1, processes[i].waiting_time, processes[i].turnaround_time);
    }
    printf("\nAverage Waiting Time: %.2f milliseconds\n", total_waiting_time/num_processes);
    printf("Average Turnaround Time: %.2f milliseconds\n", total_turnaround_time/num_processes);
    free(processes);
    return 0;
}
