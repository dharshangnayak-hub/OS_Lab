#include <stdio.h>

int main()
{
    int n, i, j;
    int at[20], bt[20], q[20];
    int ct[20], tat[20], wt[20];
    int time = 0;
    float avgwt = 0, avgtat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Queue Type: 1-System Process, 2-User Process\n");

    for(i = 0; i < n; i++)
    {
        printf("Enter AT, BT and Queue Type for P%d: ", i + 1);
        scanf("%d%d%d", &at[i], &bt[i], &q[i]);
    }

    /* Sort by Queue Priority and Arrival Time */
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(q[i] > q[j] || (q[i] == q[j] && at[i] > at[j]))
            {
                int temp;

                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = q[i];
                q[i] = q[j];
                q[j] = temp;
            }
        }
    }

    printf("\nProcess\tAT\tBT\tQ\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
    {
        if(time < at[i])
            time = at[i];

        ct[i] = time + bt[i];
        time = ct[i];

        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avgwt += wt[i];
        avgtat += tat[i];

        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], q[i],
               ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avgwt / n);
    printf("\nAverage Turnaround Time = %.2f", avgtat / n);

    return 0;
}