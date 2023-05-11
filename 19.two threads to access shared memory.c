#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
int sharedData;
sem_t semaphore;
void* thread1(void* arg) 
{
    sem_wait(&semaphore);
    int doubledValue = sharedData * 2;
    printf("Thread 1: Doubled value: %d\n", doubledValue);
    sem_post(&semaphore);
    return NULL;
}
void* thread2(void* arg) 
{
    sem_wait(&semaphore);
    int fiveTimesValue = sharedData * 5;
    printf("Thread 2: Five times value: %d\n", fiveTimesValue);
    sem_post(&semaphore);
    return NULL;
}
int main() 
{
    sharedData = 10;
    sem_init(&semaphore, 0, 1);
    pthread_t threadId1, threadId2;
    pthread_create(&threadId1, NULL, thread1, NULL);
    pthread_create(&threadId2, NULL, thread2, NULL);
    pthread_join(threadId1, NULL);
    pthread_join(threadId2, NULL);
    sem_destroy(&semaphore);
    return 0;
}
