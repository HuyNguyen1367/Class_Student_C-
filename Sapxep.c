#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n-1; i++) {
        minIndex = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main() {
    int arr[] = {1, 4, 3, 5, 7, 3, 1, 6, 9, 7, 5, 2, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i;
    printf("Mang truoc khi sap xep: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    selectionSort(arr, n);
    printf("Mang sau khi sap xep: ");
    for (i = 0; i <n;i++)
    {
    printf("%d ", arr[i]);
    }
}