#include <stdio.h>

int main() {
    int n, i, time = 0, remain, quantum;
    int burst_time[20], remaining_time[20];
    int waiting_time = 0, turnaround_time = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    remain = n;

    // Input burst times
    for(i = 0; i < n; i++) {
        printf("Enter burst time for process P%d: ", i + 1);
        scanf("%d", &burst_time[i]);
        remaining_time[i] = burst_time[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    printf("\nProcess\tTurnaround Time\tWaiting Time\n");

    int flag = 0;
    for(time = 0, i = 0; remain != 0; ) {

        if(remaining_time[i] <= quantum && remaining_time[i] > 0) {
            time += remaining_time[i];
            remaining_time[i] = 0;
            flag = 1;
        }
        else if(remaining_time[i] > 0) {
            remaining_time[i] -= quantum;
            time += quantum;
        }

        if(remaining_time[i] == 0 && flag == 1) {
            remain--;
            printf("P%d\t\t%d\t\t%d\n", i + 1,
                   time,
                   time - burst_time[i]);

            turnaround_time += time;
            waiting_time += time - burst_time[i];

            flag = 0;
        }

        if(i == n - 1)
            i = 0;
        else if(remaining_time[i + 1] > 0)
            i++;
        else
            i = 0;
    }

    printf("\nAverage Turnaround Time = %.2f",
           (float)turnaround_time / n);
    printf("\nAverage Waiting Time = %.2f",
           (float)waiting_time / n);

    return 0;
}
