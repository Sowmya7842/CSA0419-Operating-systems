#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define N 5  
enum 
{
    THINKING,
    HUNGRY,
    EATING
} 
state[N];
pthread_mutex_t mutex;
pthread_cond_t cond[N];
int left(int i) 
{
    return (i + N - 1) % N;
}
int right(int i) 
{
    return (i + 1) % N;
}
void test(int i) 
{
    if (state[i] == HUNGRY && state[left(i)] != EATING && state[right(i)] != EATING) 
	{
        state[i] = EATING;
        pthread_cond_signal(&cond[i]);
    }
}
void pickup_forks(int i) 
{
    pthread_mutex_lock(&mutex);
    state[i] = HUNGRY;
    test(i);
    while (state[i] != EATING) 
	{
        pthread_cond_wait(&cond[i], &mutex);
    }
    pthread_mutex_unlock(&mutex);
}
void return_forks(int i) 
{
    pthread_mutex_lock(&mutex);
    state[i] = THINKING;
    test(left(i));
    test(right(i));
    pthread_mutex_unlock(&mutex);
}

void *philosopher(void *arg) 
{
    int id = *(int*)arg;
    while (1) 
	{
        printf("Philosopher %d is thinking\n", id);
        sleep(2);
        printf("Philosopher %d is hungry\n", id);
        pickup_forks(id);
        printf("Philosopher %d is eating\n", id);
        sleep(2);
        printf("Philosopher %d is done eating\n", id);
        return_forks(id);
    }
}
int main() 
{
    pthread_t threads[N];
    int ids[N];
    int i;
    pthread_mutex_init(&mutex, NULL);
    for (i = 0; i < N; i++) 
	{
        pthread_cond_init(&cond[i], NULL);
        ids[i] = i;
        pthread_create(&threads[i], NULL, philosopher, &ids[i]);
    }
	for (i = 0; i < N; i++) 
	{
        pthread_join(threads[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    for (i = 0; i < N; i++) 
	{
        pthread_cond_destroy(&cond[i]);
    }
    return 0;
}
