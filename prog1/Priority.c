#include <stdio.h>

int main() {
    int n, i, current_time = 0, completed = 0;
    int at[20], bt[20], pr[20], ct[20], tat[20], wt[20], done[20];
    float avgwt = 0, avgtat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Time, Burst Time, and Priority:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
        done[i] = 0; // Mark all processes as NOT done initially
    }

    // Loop until all processes are executed
    while (completed < n) {
        int highest_priority_idx = -1;
        int highest_priority_val = 99999; // Lower number means higher priority

        // Find the process that has arrived and has the highest priority (lowest value)
        for (i = 0; i < n; i++) {
            if (at[i] <= current_time && !done[i]) {
                if (pr[i] < highest_priority_val) {
                    highest_priority_val = pr[i];
                    highest_priority_idx = i;
                }
            }
        }

        // If no process has arrived yet, advance time (CPU is idle)
        if (highest_priority_idx == -1) {
            current_time++;
        } 
        // Execute the highest priority process found
        else {
            current_time += bt[highest_priority_idx];
            ct[highest_priority_idx] = current_time;
            
            tat[highest_priority_idx] = ct[highest_priority_idx] - at[highest_priority_idx];
            wt[highest_priority_idx]  = tat[highest_priority_idx] - bt[highest_priority_idx];

            avgwt  += wt[highest_priority_idx];
            avgtat += tat[highest_priority_idx];
            
            done[highest_priority_idx] = 1; // Mark as completed
            completed++;
        }
    }

    // Print Results Table
    printf("\nProcess\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", 
               i + 1, at[i], bt[i], pr[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Waiting Time    = %.2f", avgwt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avgtat / n);

    return 0;
}