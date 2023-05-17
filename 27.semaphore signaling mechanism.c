#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#define NUM_PROCESSES 4
sem_t semaphore;
void *waitOnSemaphore(void *processName) 
{
    char *name = (char*) processName;
    printf("%s is waiting on the semaphore.\n", name);
    sem_wait(&semaphore);
    printf("%s has acquired the semaphore.\n", name);
    sem_post(&semaphore);
    printf("%s has released the semaphore.\n", name);
    pthread_exit(NULL);
}
int main() 
{
    int i;
    sem_init(&semaphore, 0, 4);
    char *processNames[NUM_PROCESSES] = {"P1", "P2", "P3", "P4"};
    pthread_t threads[NUM_PROCESSES];
    for (i = 0; i < NUM_PROCESSES; i++) 
	{
        pthread_create(&threads[i], NULL, waitOnSemaphore, (void*) processNames[i]);
    }
    for (i = 0; i < NUM_PROCESSES; i++) 
	{
        pthread_join(threads[i], NULL);
    }
    printf("Attempting to signal P5...\n");
    if (sem_trywait(&semaphore) == 0) 
	{
        printf("P5 has acquired the semaphore.\n");
        sem_post(&semaphore);
        printf("P5 has released the semaphore.\n");
    } 
	else 
	{
        printf("P5 cannot acquire the semaphore because all instances are in use.\n");
    }
    sem_destroy(&semaphore);
    return 0;
}
