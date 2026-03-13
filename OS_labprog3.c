
#include <stdio.h>

struct process {
    int pid;
    int at;
    int bt;
    int rt;
    int ct;
    int wt;
    int tat;
};

int main() {
    struct process p[20];
    int n, time = 0, completed = 0, i, min, index;
    float total_wt = 0, total_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input arrival time and burst time
    for(i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Arrival Time and Burst Time for P%d: ", p[i].pid);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].rt = p[i].bt;   // remaining time
    }

    while(completed < n) {
        min = 9999;
        index = -1;

        for(i = 0; i < n; i++) {
            if(p[i].at <= time && p[i].rt > 0 && p[i].rt < min) {
                min = p[i].rt;
                index = i;
            }
        }

        if(index != -1) {
            p[index].rt--;
            time++;

            if(p[index].rt == 0) {
                completed++;
                p[index].ct = time;
                p[index].tat = p[index].ct - p[index].at;
                p[index].wt = p[index].tat - p[index].bt;

                total_wt += p[index].wt;
                total_tat += p[index].tat;
            }
        }
        else {
            time++;
        }
    }

    printf("\nPID\tAT\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].wt, p[i].tat);
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}
