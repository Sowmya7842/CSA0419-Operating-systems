#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n = 5,i;
    int tracks[] = {55, 58, 60, 70, 18};
    int head_position, total_head_movement = 0;
    printf("Enter the initial head position: ");
    scanf("%d", &head_position);
    for (i = 0; i < n; i++) 
	{
        total_head_movement += abs(tracks[i] - head_position);
        head_position = tracks[i];
    }
    printf("Total head movement: %d\n", total_head_movement);
    printf("Average head movement: %.2f\n", (float)total_head_movement / n);
    return 0;
}
