#include <stdio.h>

int main() {
    int block[10], process[10];
    int nb, np, i, j, worst;

    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);

    printf("Enter sizes of blocks:\n");
    for(i = 0; i < nb; i++)
        scanf("%d", &block[i]);

    printf("Enter number of processes: ");
    scanf("%d", &np);

    printf("Enter sizes of processes:\n");
    for(i = 0; i < np; i++)
        scanf("%d", &process[i]);

    for(i = 0; i < np; i++) {
        worst = -1;

        for(j = 0; j < nb; j++) {
            if(block[j] >= process[i]) {
                if(worst == -1 || block[j] > block[worst]) {
                    worst = j;
                }
            }
        }

        if(worst != -1) {
            printf("Process %d allocated to Block %d\n", i+1, worst+1);
            block[worst] = block[worst] - process[i];
        }
    }

    return 0;
}
/*
Enter number of memory blocks: 5
Enter sizes of blocks:
100
500
200
300
600
Enter number of processes: 4
Enter sizes of processes:
212
417
112
426

Process 1 allocated to Block 5
Process 2 allocated to Block 2
Process 3 allocated to Block 5
*/