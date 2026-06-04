#include <stdio.h>

int main()
{
    int n, i, j;
    int period[10], burst[10];

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter Execution Time and Period for Task %d: ", i + 1);
        scanf("%d%d", &burst[i], &period[i]);
    }

    /* Sort tasks by Period (smaller period = higher priority) */
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(period[i] > period[j])
            {
                int temp;

                temp = period[i];
                period[i] = period[j];
                period[j] = temp;

                temp = burst[i];
                burst[i] = burst[j];
                burst[j] = temp;
            }
        }
    }

    printf("\nPriority Order (Rate Monotonic Scheduling):\n");

    for(i = 0; i < n; i++)
    {
        printf("Task %d  Execution Time = %d  Period = %d\n",
               i + 1, burst[i], period[i]);
    }

    return 0;
}