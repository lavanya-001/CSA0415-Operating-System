#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t mutex;
int count = 0;

void *process(void *arg)
{
    sem_wait(&mutex);

    count++;
    printf("Count = %d\n", count);

    sem_post(&mutex);

    return NULL;
}

int main()
{
    pthread_t t1, t2;

    sem_init(&mutex, 0, 1);

    pthread_create(&t1, NULL, process, NULL);
    pthread_create(&t2, NULL, process, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&mutex);

    printf("Synchronization completed.\n");

    return 0;
}
