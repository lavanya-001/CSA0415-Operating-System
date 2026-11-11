#include <stdio.h>

int main()
{
    int n, m, i, j, k;
    int alloc[10][10], max[10][10];
    int avail[10], need[10][10];
    int finish[10] = {0};
    int safe[10], count = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    printf("Enter Allocation Matrix:\n");

    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Max Matrix:\n");

    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter Available Resources:\n");

    for(j = 0; j < m; j++)
        scanf("%d", &avail[j]);

    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    for(k = 0; k < n; k++)
    {
        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                int found = 1;

                for(j = 0; j < m; j++)
                {
                    if(need[i][j] > avail[j])
                    {
                        found = 0;
                        break;
                    }
                }

                if(found)
                {
                    for(j = 0; j < m; j++)
                        avail[j] += alloc[i][j];

                    safe[count++] = i;
                    finish[i] = 1;
                }
            }
        }
    }

    if(count == n)
    {
        printf("\nSystem is in Safe State.\n");
        printf("Safe Sequence: ");

        for(i = 0; i < n; i++)
            printf("P%d ", safe[i]);
    }
    else
    {
        printf("\nSystem is not in Safe State.\n");
    }

    return 0;
}
