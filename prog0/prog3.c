//3. Write a program in C to find the sum of rows and columns of a matrix.
#include <stdio.h>

int main() {
    int mat[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    int i, j;
    for (i = 0; i < 2; i++) {
        int r = 0;
        for (j = 0; j < 3; j++)
            r += mat[i][j];
        printf("Sum of row %d: %d\n", i + 1, r);
    }
    for (j = 0; j < 3; j++) {
        int c = 0;
        for (i = 0; i < 2; i++)
            c += mat[i][j];
        printf("Sum of column %d: %d\n", j + 1, c);
    }
    return 0;
}