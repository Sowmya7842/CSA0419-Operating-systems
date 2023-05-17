#include <stdio.h>
#include <pthread.h>
#define MAX_NUMBER 20
void *printEvenNumbers(void *arg) 
{
	int i;
    printf("Even numbers: ");
    for (i = 0; i <= MAX_NUMBER; i += 2) 
	{
        printf("%d ", i);
    }
    printf("\n");
    pthread_exit(NULL);
}
void *printOddNumbers(void *arg) 
{
	int i;
    printf("\nOdd numbers: ");
    for (i = 1; i <= MAX_NUMBER; i += 2) 
	{
        printf("%d ", i);
    }
    printf("\n");
    pthread_exit(NULL);
}
int main() 
{
    pthread_t evenThread, oddThread;
    if (pthread_create(&evenThread, NULL, printEvenNumbers, NULL) != 0) 
	{
        printf("Failed to create even thread.\n");
        return 1;
    }
    if (pthread_create(&oddThread, NULL, printOddNumbers, NULL) != 0) 
	{
        printf("Failed to create odd thread.\n");
        return 1;
    }
    pthread_join(evenThread, NULL);
    pthread_join(oddThread, NULL);
    return 0;
}
