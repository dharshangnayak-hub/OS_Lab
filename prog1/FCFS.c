#include <stdio.h>

int main() {
    int n, i, j, temp;
    int at[20], bt[20], ct[20], tat[20], wt[20];
    float avgwt = 0, avgtat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Time and Burst Time:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    // 1. Sort processes by Arrival Time (Bubble Sort)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                // Swap Arrival Time
                temp = at[j]; at[j] = at[j + 1]; at[j + 1] = temp;
                // Swap Burst Time
                temp = bt[j]; bt[j] = bt[j + 1]; bt[j + 1] = temp;
            }
        }
    }

    // 2. Calculate Times
    int current_time = 0;
    for (i = 0; i < n; i++) {
        // If CPU is idle waiting for the next process to arrive
        if (current_time < at[i]) {
            current_time = at[i]; 
        }
        
        current_time += bt[i]; // CPU executes the process
        ct[i] = current_time;  // Completion Time
        
        tat[i] = ct[i] - at[i]; // Turnaround Time = Completion - Arrival
        wt[i] = tat[i] - bt[i];  // Waiting Time = Turnaround - Burst
        
        avgwt += wt[i];
        avgtat += tat[i];
    }

    // 3. Print Table
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Waiting Time    = %.2f", avgwt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avgtat / n);

    return 0;
}