#include<stdio.h>
int main() 
{
    int frames, pages, faults = 0, count = 0, i, j, k, flag = 0;
    printf("Enter the number of page frames: ");
    scanf("%d", &frames);
    int queue[frames];
    for(i = 0; i < frames; i++) 
	{
        queue[i] = -1;
    }
    printf("Enter the number of pages: ");
    scanf("%d", &pages);
    int arr[pages];
    printf("Enter the page reference sequence: ");
    for(i = 0; i < pages; i++) 
	{
        scanf("%d", &arr[i]);
    }
    printf("\nPage reference sequence:\n");
    for(i = 0; i < pages; i++) 
	{
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    for(i = 0; i < pages; i++) 
	{
        flag = 0;
        for(j = 0; j < frames; j++) 
		{
            if(queue[j] == arr[i]) 
			{
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            faults++;
            queue[count] = arr[i];
            count = (count + 1) % frames;
        }
        printf("\n\n");
        for(k = 0; k < frames; k++) {
            printf("%d ", queue[k]);
        }
    }
    printf("\n\nTotal page faults: %d", faults);
    return 0;
}

