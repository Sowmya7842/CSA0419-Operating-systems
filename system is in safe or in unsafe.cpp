#include<stdio.h>
int main() 
{
    int processes = 4, resources = 3, i, j, k, count = 0, safe = 0;
    int allocation[4][3] = {{1, 0, 0}, {6, 1, 2}, {2, 1, 1}, {0, 0, 2}};
    int max[4][3] = {{3, 2, 2}, {6, 1, 3}, {3, 1, 4}, {4, 2, 2}};
    int available[3] = {9, 3, 6};
    int need[4][3];
    int finish[4] = {0};
    int work[3];
    for(i = 0; i < processes; i++) 
	{
        for(j = 0; j < resources; j++) 
		{
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    for(i = 0; i < resources; i++) 
	{
        work[i] = available[i];
    }
    while(count < processes) 
	{
        safe = 0;
        for(i = 0; i < processes; i++) 
		{
            if(finish[i] == 0) 
			{
                int flag = 1;
                for(j = 0; j < resources; j++) 
				{
                    if(need[i][j] > work[j]) 
					{
                        flag = 0;
                        break;
                    }
                }
                if(flag == 1) 
				{
                    for(k = 0; k < resources; k++) 
					{
                        work[k] += allocation[i][k];
                    }
                    finish[i] = 1;
                    safe = 1;
                    count++;
                    break;
                }
            }
        }
        if(safe == 0) 
		{
            break;
        }
    }
    if(safe == 1) 
	{
        printf("The system is in a safe state.\n");
    } 
	else 
	{
        printf("The system is in an unsafe state.\n");
    }
    return 0;
}


