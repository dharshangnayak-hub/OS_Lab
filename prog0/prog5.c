//5. Write a program in C to find the second largest element in an array.
#include <stdio.h>

int main() {
    int arr[] = {5, 2, 8, 1, 3};
    int n = 5;
    int largest=-9999, s_largest=-9999;
    for (int i=0;i<n;i++) {
        if (arr[i]>largest) {
            s_largest=largest;
            largest=arr[i];
        } else if (arr[i]<largest && arr[i]>s_largest) {
            s_largest=arr[i];
        }
    }
    printf("Second largest: %d\n", s_largest);
    return 0;
}