#include <stdio.h>
#define MAX_FRAMES 3
int findLongestFuture(int pages[], int n, int current, int frames[], int m) 
{
    int i,index = -1, farthest = current;
    for (i = 0; i < m; i++) 
	{
        int j;
        for (j = current; j < n; j++) 
		{
            if (frames[i] == pages[j]) 
			{
                if (j > farthest) 
				{
                    farthest = j;
                    index = i;
                }
                break;
            }
        }
        if (j == n)
            return i;
    }
    return (index == -1) ? 0 : index;
}
int pageFaults(int pages[], int n, int framesCount) 
{
    int frames[MAX_FRAMES] = {0};
    int faults = 0;
	int i;
    for (i = 0; i < n; i++) 
	{
        int j;
        for (j = 0; j < framesCount; j++) 
		{
            if (frames[j] == pages[i])
                break;
        }

        if (j == framesCount) 
		{
            int replaceIndex = findLongestFuture(pages, n, i + 1, frames, framesCount);
            frames[replaceIndex] = pages[i];
            faults++;
        }
    }
    return faults;
}
int main() 
{
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int n = sizeof(pages) / sizeof(pages[0]);
    int framesCount = 3;
    int totalFaults = pageFaults(pages, n, framesCount);
    printf("Number of page faults: %d\n", totalFaults);
    return 0;
}
