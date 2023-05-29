#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int isPrime(int num) 
{
	int i;
    if (num <= 1) 
	{
        return 0;
    }
    for (i = 2; i * i <= num; i++) 
	{
        if (num % i == 0) 
		{
            return 0;
        }
    }
    return 1;
}
void generateFibonacci(int n) 
{
    int first = 0, second = 1;
    int i;
    printf("Fibonacci Series: %d %d ", first, second);
    for (i = 2; i < n; i++) 
	{
        int next = first + second;
        printf("%d ", next);
        first = second;
        second = next;
    }
    printf("\n");
}
int main() 
{
    pid_t pid;
    int status;
    int i;
    pid = fork();
    if (pid < 0) 
	{
        fprintf(stderr, "Fork Failed\n");
        return 1;
    } 
	else if (pid == 0) 
	{
        printf("Child Process\n");
        int n = 10; 
        generateFibonacci(n);
    } 
	else 
	{
        printf("Parent Process\n");
        wait(&status);
        printf("Prime Numbers: ");
        for (i = 2; i <= 20; i++) 
		{
            if (isPrime(i)) 
			{
                printf("%d ", i);
            }
        }
        printf("\n");
    }
    return 0;
}
