#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size){
    printf("[ ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
        if(i < size - 1) printf(", ");
    }
    printf(" ]\n");
}

void bubbleSort(int arr[], int size){
    printf("Bubble Sort Trace\n\n");
    printf("Initial Array: ");
    printArray(arr, size);

    for (int i = 0; i < size - 1; i++){
        int swaps = 0;
        int comparisons = size - 1 - i;

        printf("\nPass %d: (%d comparisons, places %d)\n", i + 1, comparisons, arr[size - i - 1]);
        for (int j = 0; j < size - i - 1; j++){
            printf(" Compare (%d, %d): ", arr[j], arr[j + 1]);
            if(arr[j] > arr[j + 1]){
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                swaps++;
                printf("SWAP! -> ");
            } else {
                printf(" No Swap. -> ");
            }
            printArray(arr, size);
        }
        printf(" Array End Pass %d: ", i + 1);
        printArray(arr, size);
    }
    printf("\n--- Final Sorted Array (Bubble Sort) ---\n");
    printf("Sorted Array: ");
    printArray(arr, size);
}

void selectionSort(int arr[], int size){
    printf("Selection Sort Trace\n\n");
    printf("Initial Array: ");
    printArray(arr, size);

    for (int i = 0; i < size - 1; i++){
        int min_index = i;
        int min_element = arr[i];

        printf("\nPass %d (i=%d): Find Min in unsorted array [", i + 1, i);
        for (int  k = i; k < size; k++){
            printf("%d", arr[k]);
            if (k < size - 1) printf(", ");
        }
        printf("]\n");
        printf(" Start Scan: min_element = %d, min_index = %d\n", min_element, min_index);

        for (int j = i + 1; j < size; j++){
            if (arr[j] < min_element){
                printf(" Compare data[%d] (%d) < %d: New Min (%d) at index %d\n", j, arr[j], min_element, arr[j], j);
                min_element = arr[j];
                min_index = j;
            } else {
                printf(" Compare data[%d] (%d) < %d: No Change.\n", j, arr[j], min_element);
            }
        }
        printf(" End Scan: Minimum element %d found at index %d\n", min_element, min_index);

        if(min_index != i){
            printf(" SWAP (data[%d] = %d, data[%d] = %d)\n", i, arr[i], min_index, arr[min_index]);
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        } else {
            printf(" SWAP (data[%d] = %d, data[%d] = %d). (No change)\n", i, arr[i], min_index, arr[min_index]);
        }
        printf(" Arrat State: ");
        printArray(arr, size);
    }
    printf("\n--- Final Sorted Array (Selection Sort) ---\n");
    printf("Sorted Array: ");
    printArray(arr, size);
}

void insertionSort(int arr[], int size){
    printf("Insertion Sort Trace\n\n");
    printf("Initial Array: ");
    printArray(arr, size);

    for (int i = 1; i < size; i++){
        int key = arr[i];
        int j = i - 1;

        printf("\nPass %d (i=%d, key=%d): Inserted %d into sorted part [", i, i, key, key);
        for (int k = 0; k < i; k++){
            printf("%d", arr[k]);
            if( k < i - 1) printf(", ");
        }
        printf("]\n");

        printf(" Key: %d. Start comparison at index j = %d (value %d).\n", key, j, arr[j]);

        while(j >= 0 && arr[j] > key){
            printf(" Compare key (%d) < Array[%d] (%d): TRUE. Shift %d right.\n", key, j, arr[j], arr[j]);
            arr[j + 1] = arr[j];
            j--;
            if(j >= 0){
                printf(" Compare key (%d) < Array[%d] (%d): ", key, j, arr[j]);
            }
            if(j >= 0 && arr[j] <= key){
                printf(" Compare key (%d) < Array[%d] (%d): FALSE. Stop comparisons.\n", key, j, arr[j]);
            } else if (j < 0){
                printf(" j becomes -1. Stop comparisons.\n");
            } 
            arr[j + 1] = key;
            printf(" INSERT %d at index %d.\n", key, j + 1);
            printf(" Array State: ");
            printArray(arr, size);

            printf(" Sorted Part: [");
            for (int k = 0; k <= 1; k++){
                printf("%d", arr[k]);
                if( k < 1) printf(", ");
            }
            printf("]\n");
        }
        printf("\n--- Final Sorted Array (Insertion Sort) ---\n");
        printf("Sorted Array: ");
        printArray(arr, size);
    }
}

int main(){

    int data[] = { 73, 22, 95, 11, 6, 88, 34, 47, 51, 19 };

    int size = sizeof(data) / sizeof(data[0]);
    int choice;
    
    do {
        printf("Choose sorting algorithm:\n");
        printf("1. Bubble Sort\n");
        printf("2. Insertion Sort\n");
        printf("3. Selection Sort\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
    } while (choice < 1 || choice > 3);

    switch (choice)
    {
    case 1:
        bubbleSort(data, size);
        break;
    case 2:
        insertionSort(data, size);
        break;
    case 3:
        selectionSort(data, size);
        break;
    default:
        printf("Invalid choice!\n");
        break;
    }

    return 0;
}