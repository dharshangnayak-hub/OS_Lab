//1. Write a program in C to find the second smallest element in an array.
#include <stdio.h>

int main() {
    int arr[] = {3,4,6,7,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int smallest=9999, s_smallest=9999;
    for (int i=0;i<n;i++) {
        if (arr[i]<smallest) {
            s_smallest=smallest;
            smallest=arr[i];
        } else if(arr[i]>smallest && arr[i]<s_smallest) {
            s_smallest=arr[i];
        }
    }
    printf("Second smallest: %d\n", s_smallest);
    return 0;
}