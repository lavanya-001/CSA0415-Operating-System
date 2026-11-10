#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    char buffer[100];

    fd = open("test.txt", O_RDONLY);

    if (fd < 0)
    {
        printf("File opening failed\n");
        return 1;
    }

    int n = read(fd, buffer, 99);
    buffer[n] = '\0';

    printf("File content: %s\n", buffer);

    close(fd);

    return 0;
}
