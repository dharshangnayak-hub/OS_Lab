#include <stdio.h>

int main() {
    int n, i, j, temp, current_time = 0, completed = 0;
    int at[20], bt[20], ct[20], tat[20], wt[20], done[20];
    float avgwt = 0, avgtat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Time and Burst Time:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        done[i] = 0; // Mark all processes as NOT done initially
    }

    // Loop until all processes are executed
    while (completed < n) {
        int min_idx = -1;
        int min_bt = 99999; // Set a high initial burst time to find the minimum

        // Find the process that has arrived and has the shortest burst time
        for (i = 0; i < n; i++) {
            if (at[i] <= current_time && !done[i]) {
                if (bt[i] < min_bt) {
                    min_bt = bt[i];
                    min_idx = i;
                }
            }
        }

        // If no process has arrived yet, advance the time (CPU is idle)
        if (min_idx == -1) {
            current_time++;
        } 
        // If a process is found, execute it completely
        else {
            current_time += bt[min_idx];
            ct[min_idx] = current_time;
            tat[min_idx] = ct[min_idx] - at[min_idx];
            wt[min_idx] = tat[min_idx] - bt[min_idx];

            avgwt += wt[min_idx];
            avgtat += tat[min_idx];
            
            done[min_idx] = 1; // Mark as completed
            completed++;
        }
    }

    // Print Results Table
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Waiting Time    = %.2f", avgwt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avgtat / n);

    return 0;
}