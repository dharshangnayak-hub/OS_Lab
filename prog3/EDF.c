#include <stdio.h>

int main()
{
    int n, i, j;
    int bt[10], deadline[10];

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter Burst Time and Deadline for Task %d: ", i + 1);
        scanf("%d%d", &bt[i], &deadline[i]);
    }

    /* Sort by Deadline */
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(deadline[i] > deadline[j])
            {
                int temp;

                temp = deadline[i];
                deadline[i] = deadline[j];
                deadline[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }

    printf("\nExecution Order (EDF):\n");

    for(i = 0; i < n; i++)
    {
        printf("Task %d  BT = %d  Deadline = %d\n",
               i + 1, bt[i], deadline[i]);
    }

    return 0;
}