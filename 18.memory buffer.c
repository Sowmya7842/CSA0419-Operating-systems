#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define BUFFER_SIZE 3
int buffer[BUFFER_SIZE];
int bufferCount = 0;
int produceIndex = 0;
int consumeIndex = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t full = PTHREAD_COND_INITIALIZER;
pthread_cond_t empty = PTHREAD_COND_INITIALIZER;
void* producer(void* arg) 
{
	int i;
    for (i = 0; i < 4; i++) 
	{
        pthread_mutex_lock(&mutex);
        while (bufferCount == BUFFER_SIZE) 
		{
            printf("Buffer is full. Producer is waiting...\n");
            pthread_cond_wait(&full, &mutex);
        }
        int item = rand() % 100;
        buffer[produceIndex] = item;
        printf("Produced item: %d\n", item);
        produceIndex = (produceIndex + 1) % BUFFER_SIZE;
        bufferCount++;
        pthread_cond_signal(&empty);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}
void* consumer(void* arg) 
{
    pthread_mutex_lock(&mutex);
    while (bufferCount == 0) 
	{
        printf("Buffer is empty. Consumer is waiting...\n");
        pthread_cond_wait(&empty, &mutex);
    }
    int item = buffer[consumeIndex];
    printf("Consumed item: %d\n", item);
    consumeIndex = (consumeIndex + 1) % BUFFER_SIZE;
    bufferCount--;
    pthread_cond_signal(&full);
    pthread_mutex_unlock(&mutex);
    return NULL;
}
int main() 
{
    pthread_t producerThread, consumerThread;
    pthread_create(&consumerThread, NULL, consumer, NULL);
    pthread_join(consumerThread, NULL);
    printf("Buffer is EMPTY\n");
    pthread_create(&producerThread, NULL, producer, NULL);
    pthread_join(producerThread, NULL);
    printf("Buffer is FULL\n");
    return 0;
}
