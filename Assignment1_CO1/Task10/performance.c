#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>
#include <time.h>

void *task(void *arg)
{
    return NULL;
}

int main()
{
    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC, &start);

    for (int i = 0; i < 1000; i++)
    {
        if (fork() == 0)
            _exit(0);
        wait(NULL);
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    printf("1000 Processes Time: %.4f seconds\n",
    (end.tv_sec-start.tv_sec) +
    (end.tv_nsec-start.tv_nsec)/1e9);

    clock_gettime(CLOCK_MONOTONIC, &start);

    pthread_t t;

    for (int i = 0; i < 1000; i++)
    {
        pthread_create(&t, NULL, task, NULL);
        pthread_join(t, NULL);
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    printf("1000 Threads Time: %.4f seconds\n",
    (end.tv_sec-start.tv_sec) +
    (end.tv_nsec-start.tv_nsec)/1e9);

    return 0;
}
