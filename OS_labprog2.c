#include <stdio.h>

struct process {
    int pid;
    int at;
    int bt;
    int ct;
    int wt;
    int tat;
    int completed;
};

int main() {
    struct process p[20];
    int n, time = 0, done = 0, i, min, index;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input arrival and burst time
    for(i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for P%d: ", i + 1);
        p[i].pid = i + 1;
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].completed = 0;
    }

    while(done < n) {
        min = 9999;
        index = -1;

        for(i = 0; i < n; i++) {
            if(p[i].at <= time && p[i].completed == 0 && p[i].bt < min) {
                min = p[i].bt;
                index = i;
            }
        }

        if(index != -1) {
            time += p[index].bt;
            p[index].ct = time;
            p[index].tat = p[index].ct - p[index].at;
            p[index].wt = p[index].tat - p[index].bt;
            p[index].completed = 1;
            done++;
        } else {
            time++;
        }
    }

    printf("\nPID\tAT\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].wt, p[i].tat);
    }

    return 0;
}
