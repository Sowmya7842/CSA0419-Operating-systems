#include <stdio.h>
#define N 3		
#define M 3		
int main()
{
    int max[N][M] = {{3, 6, 8}, {4, 3, 3}, {3, 4, 4}};	
    int allocation[N][M] = {{3, 3, 3}, {2, 0, 3}, {1, 2, 4}};	
    int available[M] = {1, 2, 0};				
	int i,j,k;
    int need[N][M];			
    int finish[N] = {0};		
    int work[M];		
    int safeSeq[N];		
    for ( i = 0; i < N; i++) 
	{
        for (j = 0; j < M; j++) 
		{
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    for ( j = 0; j < M; j++) 
	{
        work[j] = available[j];
    }

    int count = 0;	
    while (count < N) 
	{
        int found = 0;
        for (i = 0; i < N; i++) 
		{
            if (!finish[i]) 
			{	
                for (j = 0; j < M; j++) 
				{
                    if (need[i][j] > work[j]) 
					{	
                        break;
                    }
                }
                if (j == M) 
				{	
                    for ( k = 0; k < M; k++) 
					{
                        work[k] += allocation[i][k];
                    }
                    finish[i] = 1;		
                    safeSeq[count] = i;	
                    count++;
                    found = 1;	
                }
            }
        }
        if (!found) 
		{	
            printf("Deadlock detected.\n");
            return 0;
        }
    }
    printf("Safe sequence: ");
    for (i = 0; i < N; i++) 
	{
        printf("%d ", safeSeq[i]);
    }
    printf("\n");
    return 0;
}

