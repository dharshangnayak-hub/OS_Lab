//2. Write a program in C to find the sum of the left diagonals of a matrix.
#include <stdio.h>

int main() {
    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int sum = 0;
    for (int i = 0; i < 3; i++) {
            for (int j=0; j<3;j++) {
                if (i>=j) {
                    sum+=mat[i][j];
                }
            }
    }
    printf("Sum of left diagonals: %d\n", sum);
    return 0;
}