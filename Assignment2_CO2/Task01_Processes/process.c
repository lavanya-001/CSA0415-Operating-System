#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int i;
    pid_t pid;

    for(i = 1; i <= 3; i++)
    {
        pid = fork();

        if(pid == 0)
        {
            printf("Child Process %d, PID = %d\n", i, getpid());
            exit(0);
        }
    }

    for(i = 0; i < 3; i++)
    {
        wait(NULL);
    }

    printf("Parent process completed.\n");

    return 0;
}
