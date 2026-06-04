#include <stdio.h>

int main() {
    int n, q, i, current_time = 0, completed = 0;
    int at[20], bt[20], ct[20], tat[20], wt[20], rem_bt[20];
    float avgwt = 0, avgtat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter Time Quantum: ");
    scanf("%d", &q);

    printf("Enter Arrival Time and Burst Time:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rem_bt[i] = bt[i]; // Initialize remaining burst time
    }

    // Loop until all processes are fully executed
    while (completed < n) {
        int executed_any = 0; // Flag to check if any process ran in this cycle

        for (i = 0; i < n; i++) {
            // Process can run only if it has arrived and has remaining time
            if (at[i] <= current_time && rem_bt[i] > 0) {
                executed_any = 1;

                if (rem_bt[i] <= q) {
                    // Process finishes in this quantum
                    current_time += rem_bt[i];
                    rem_bt[i] = 0;
                    
                    ct[i] = current_time;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];
                    
                    completed++;
                } else {
                    // Process needs more time than the quantum
                    current_time += q;
                    rem_bt[i] -= q;
                }
            }
        }

        // If no process was ready to execute, the CPU sits idle
        if (executed_any == 0) {
            current_time++;
        }
    }

    // Print Results Table
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
        avgwt += wt[i];
        avgtat += tat[i];
    }

    printf("\nAverage Waiting Time    = %.2f", avgwt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avgtat / n);

    return 0;
}