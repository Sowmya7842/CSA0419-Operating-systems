#include <stdio.h>
int findOptimal(int pages[], int n, int frame[], int frameSize, int currentPosition) 
{
	int i;
    int opt = -1, farthest = currentPosition;
    for (i = 0; i < frameSize; i++) 
	{
        int j;
        for (j = currentPosition; j < n; j++) 
		{
            if (frame[i] == pages[j]) 
			{
                if (j > farthest) 
				{
                    farthest = j;
                    opt = i;
                }
                break;
            }
        }
        if (j == n)
            return i;
    }
    return (opt == -1) ? 0 : opt;
}
int i;
int isPageFault(int page, int frame[], int frameSize) 
{
    for (i = 0; i < frameSize; i++) 
	{
        if (frame[i] == page)
            return 0;
    }
    return 1;
}
void printPageFaults(int pages[], int n, int frameSize) 
{
	int i,j;
    int frame[frameSize];
    int faults = 0;
    for (i = 0; i < frameSize; i++) 
	{
        frame[i] = -1; 
    }
    for (i = 0; i < n; i++) 
	{
        if (isPageFault(pages[i], frame, frameSize)) 
		{
            int index = findOptimal(pages, n, frame, frameSize, i + 1);
            frame[index] = pages[i];
            faults++;
        }
        printf("Page Reference: %d\n", pages[i]);
        printf("Page Frames: ");
        for (j = 0; j < frameSize; j++) 
		{
            if (frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }
        printf("\n\n");
    }
    printf("Number of Page Faults: %d\n", faults);
}
int main() 
{
    int pageFrames = 3;
    int pageReference[] = {4, 1, 2, 4, 3, 2, 1, 5};
    int numPages = sizeof(pageReference) / sizeof(pageReference[0]);
    printPageFaults(pageReference, numPages, pageFrames);
    return 0;
}
