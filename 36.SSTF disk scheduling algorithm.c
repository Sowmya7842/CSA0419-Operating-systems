#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int absolute(int a, int b) 
{
    return abs(a - b);
}
int findClosest(int tracks[], int n, int head_position, int visited[]) 
{
    int min_distance = INT_MAX;
    int closest_track,i;
    for (i = 0; i < n; i++) 
	{
        if (!visited[i] && absolute(tracks[i], head_position) < min_distance) 
		{
            min_distance = absolute(tracks[i], head_position);
            closest_track = i;
        }
    }
    return closest_track;
}
void sstf(int tracks[], int n, int head_position) 
{
	int i;
    int visited[n];
    for (i = 0; i < n; i++) 
	{
        visited[i] = 0;
    }
    int total_head_movement = 0;
    int current_track = -1;
    printf("SSTF Disk Scheduling:\n");
    printf("Sequence: ");
    for (i = 0; i < n; i++) 
	{
        current_track = findClosest(tracks, n, head_position, visited);
        visited[current_track] = 1;
        printf("%d ", tracks[current_track]);
        total_head_movement += absolute(tracks[current_track], head_position);
        head_position = tracks[current_track];
    }
    printf("\n");
    float average_head_movement = (float)total_head_movement / n;
    printf("Average head movement: %.2f\n", average_head_movement);
}
int main() 
{
    int tracks[] = {55, 58, 60, 70, 18};
    int n = sizeof(tracks) / sizeof(tracks[0]);
    int head_position = 50; 
    sstf(tracks, n, head_position);
    return 0;
}
