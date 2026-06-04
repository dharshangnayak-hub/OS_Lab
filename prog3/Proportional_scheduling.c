#include <stdio.h>

int main()
{
    int n, i;
    int share[10], total = 0;
    float cpu_time = 100;   // Total CPU time

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter share (weight) for Task %d: ", i + 1);
        scanf("%d", &share[i]);
        total += share[i];
    }

    printf("\nProportional Scheduling:\n");
    printf("Task\tShare\tCPU Time Allocated\n");

    for(i = 0; i < n; i++)
    {
        float allocated = (share[i] * cpu_time) / total;

        printf("T%d\t%d\t%.2f\n",
               i + 1, share[i], allocated);
    }

    return 0;
}