#include <stdio.h>
#include <stdlib.h>
int abs(int a) 
{
    return a > 0 ? a : -a;
}
int main() 
{
    int n = 9;
    int tracks[] = {55, 58, 60, 70, 18, 90, 150, 160, 184};
    int i,head, totalHeadMovement;
    head = totalHeadMovement = 0;
    for ( i = 0; i < n; i++) 
	{
        totalHeadMovement += abs(head - tracks[i]);
        head = tracks[i];
    }
    float averageHeadMovement = (float)totalHeadMovement / n;
    printf("Average head movement: %.2f\n", averageHeadMovement);
    return 0;
}
