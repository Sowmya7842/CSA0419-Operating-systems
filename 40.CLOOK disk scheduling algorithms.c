#include <stdio.h>
#include <stdlib.h>
int abs_diff(int a, int b) 
{
    return abs(a - b);
}
int findIndex(int tracks[], int n, int head) 
{
    int i,index = -1;
    int minDiff = 9999;
    for (i = 0; i < n; i++) 
	{
        if (tracks[i] == -1)
            continue;
        int diff = abs_diff(tracks[i], head);
        if (diff < minDiff) 
		{
            minDiff = diff;
            index = i;
        }
    }
    return index;
}
void clook(int tracks[], int n, int head) 
{
    int totalHeadMovement = 0;
    int currentPosition = head;
    int index;
    printf("Head Movement Order: %d ", currentPosition);
    while (1) 
	{
        index = findIndex(tracks, n, currentPosition);
        if (index == -1)
            break;
        totalHeadMovement += abs_diff(currentPosition, tracks[index]);
        currentPosition = tracks[index];
        printf("%d ", currentPosition);
        tracks[index] = -1;
    }
    int i,minTrack = 9999;
    int minIndex = -1;
    for (i = 0; i < n; i++) 
	{
        if (tracks[i] != -1 && tracks[i] < minTrack) 
		{
            minTrack = tracks[i];
            minIndex = i;
        }
    }
    if (minIndex != -1) 
	{
        currentPosition = minTrack;
        printf("%d ", currentPosition);
        totalHeadMovement += abs_diff(currentPosition, tracks[minIndex]);
        currentPosition++;
        while (1) 
		{
            index = findIndex(tracks, n, currentPosition);
            if (index == -1)
                break;
            totalHeadMovement += abs_diff(currentPosition, tracks[index]);
            currentPosition = tracks[index];
            printf("%d ", currentPosition);
            tracks[index] = -1;
        }
    }
    printf("\nAverage Head Movement: %.2f\n", (float)totalHeadMovement / n);
}
int main() 
{
    int numTracks = 5;
    int trackPositions[] = {55, 58, 60, 70, 18};
    int headPosition;
    printf("Enter the initial head position: ");
    scanf("%d", &headPosition);
    clook(trackPositions, numTracks, headPosition);
    return 0;
}
