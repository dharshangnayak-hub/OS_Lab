//6. Write a program in C to delete an element at a desired position from an array.
#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5, pos = 3, i;
    for (i = pos - 1; i < n - 1; i++)
        arr[i] = arr[i + 1];
    n--;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}