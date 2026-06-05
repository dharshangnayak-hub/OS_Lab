//4. Write a program in C to count the total number of duplicate elements in an array.
#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 2, 4, 1, 5};
    int n = 7, i, j, c = 0, v[7] = {0};
    for (i = 0; i < n; i++)
        if (!v[i])
            for (j = i + 1; j < n; j++)
                if (arr[i] == arr[j]) {
                    c++;
                    v[j] = 1;
                }
    printf("Total duplicate elements: %d\n", c);
    return 0;
}