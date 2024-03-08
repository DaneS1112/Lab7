#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort
int bubbleSort(int arr[], int n, int swaps[]) {
    int totalSwaps = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swaps[arr[j]]++;
                swaps[arr[j + 1]]++;
                totalSwaps += 2;
            }
        }
    }
    return totalSwaps/2;
}

// Selection Sort
int selectionSort(int arr[], int n, int swaps[]) {
    int totalSwaps = 0;
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            swap(&arr[min_index], &arr[i]);
            swaps[arr[i]]++;
            swaps[arr[min_index]]++;
            totalSwaps += 2;
        }
    }
    return totalSwaps/2;
}

int main() {
    // Initialize arrays and length of
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);
    
    // Initialize swap counts for each number
    int swaps1[100] = {0}; // Assuming numbers range from 0 to 99
    int swaps2[100] = {0}; // Assuming numbers range from 0 to 99

    int bubble_swaps1 = bubbleSort(array1, n1, swaps1);
    printf("Array1 bubble sort:\n");
    for (int i = 0; i < n1; i++) {
        printf("%d: %d\n", array1[i], swaps1[array1[i]]);
    }
    printf("%d\n\n", bubble_swaps1);

    int bubble_swaps2 = bubbleSort(array2, n2, swaps2);
    printf("\nArray2 bubble sort:\n");
    for (int i = 0; i < n2; i++) {
        printf("%d: %d\n", array2[i], swaps2[array2[i]]);
    }
    printf("%d\n", bubble_swaps2);

    // Reset swap counts for Selection Sort
    for (int i = 0; i < 100; i++) {
        swaps1[i] = 0;
        swaps2[i] = 0;
    }

    int array3[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array4[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    int selection_swaps1 = selectionSort(array3, n1, swaps1);
    printf("\nArray1 selection swap: \n");
    for (int i = 0; i < n1; i++) {
        printf("%d: %d\n", array1[i], swaps1[array1[i]]);
    }
    printf("%d\n", selection_swaps1);

    int selection_swaps2 = selectionSort(array4, n2, swaps2);
    printf("\nArray2 selection swap:\n");
    for (int i = 0; i < n2; i++) {
        printf("%d: %d\n", array2[i], swaps2[array2[i]]);
    }
    printf("%d\n", selection_swaps2);

    return 0;
}
    

