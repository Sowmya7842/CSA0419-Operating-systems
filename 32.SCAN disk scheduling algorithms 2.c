#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b) 
{
    return (*(int*)a - *(int*)b);
}
int main() 
{
    int tracks[] = {55, 58, 60, 70, 18, 90, 150, 160, 184};
    int n = sizeof(tracks) / sizeof(tracks[0]);
    int head_position = 50; 
    int total_head_movement = 0;
    int i;
    qsort(tracks, n, sizeof(int), compare);
    for (i = 0; i < n; i++) 
	{
        if (head_position < tracks[i]) 
		{
            break;
        }
    }
    for (; i < n; i++) 
	{
        printf("Move from %d to %d\n", head_position, tracks[i]);
        total_head_movement += abs(tracks[i] - head_position);
        head_position = tracks[i];
    }
    printf("Move from %d to %d\n", head_position, 199);
    total_head_movement += 199 - head_position;
    head_position = 199;
    for (i = n - 1; i >= 0; i--) 
	{
        printf("Move from %d to %d\n", head_position, tracks[i]);
        total_head_movement += abs(tracks[i] - head_position);
        head_position = tracks[i];
    }
    float average_head_movement = (float)total_head_movement / n;
    printf("\nAverage head movement: %.2f\n", average_head_movement);
    return 0;
}
