#include <stdio.h>
#include <stdlib.h>
#define DIRECTION_LEFT 0
#define DIRECTION_RIGHT 1
int abs(int x) 
{
    return (x < 0) ? -x : x;
}
int cmpfunc(const void *a, const void *b) 
{
    return (*(int *)a - *(int *)b);
}
int scan(int tracks[], int n, int start, int direction) 
{
    int total_head_movement = 0;
    int current_track = start;
    int i, j, k;
    if (direction == DIRECTION_LEFT) 
	{
        for (i = current_track; i >= 0; i--) 
		{
            printf("%d ", i);
            total_head_movement += abs(current_track - i);
            current_track = i;
        }
        printf("0 ");
        total_head_movement += current_track;
        for (j = current_track + 1; j < n; j++) 
		{
            printf("%d ", j);
            total_head_movement += abs(current_track - j);
            current_track = j;
        }
    } 
	else if (direction == DIRECTION_RIGHT) 
	{
        for (k = current_track; k < n; k++) 
		{
            printf("%d ", k);
            total_head_movement += abs(current_track - k);
            current_track = k;
        }
        for (j = current_track - 1; j >= 0; j--) 
		{
            printf("%d ", j);
            total_head_movement += abs(current_track - j);
            current_track = j;
        }
    }
    return total_head_movement;
}
int main() 
{
    int tracks[] = {55, 58, 60, 70, 18};
    int n = sizeof(tracks) / sizeof(tracks[0]);
    int start = 50; 
    int direction = DIRECTION_RIGHT;
    int total_head_movement;
    qsort(tracks, n, sizeof(int), cmpfunc);
    printf("Order of track movements: ");
    total_head_movement = scan(tracks, n, start, direction);
    printf("\n");
    printf("Total head movement: %d\n", total_head_movement);
    printf("Average head movement: %.2f\n", (float)total_head_movement / n);
    return 0;
}
