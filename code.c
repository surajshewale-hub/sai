#include <stdio.h>
#include <stdlib.h>

// Function to dynamically allocate memory for an array of integers
int* createArray(int size) {
    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    return arr;
}

// Function to insert a new package weight at a given index
void insert(int* arr, int* size, int index, int weight) {
    if (index < 0 || index > *size) {
        printf("Invalid index for insertion!\n");
        return;
    }

    // Increase the size of the array
    (*size)++;

    // Reallocate memory to accommodate the new size
    arr = (int*)realloc(arr, *size * sizeof(int));
    if (arr == NULL) {
        printf("Memory reallocation failed!\n");
        exit(1);
    }

    // Shift elements to the right to make space for the new weight
    for (int i = *size - 1; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the new weight
    arr[index] = weight;
}

// Function to delete a package weight at a given index
void delete(int* arr, int* size, int index) {
    if (index < 0 || index >= *size) {
        printf("Invalid index for deletion!\n");
        return;
    }

    // Shift elements to the left to fill the gap
    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Decrease the size of the array
    (*size)--;


    arr = (int*)realloc(arr, *size * sizeof(int));
    if (arr == NULL) {
        printf("Memory reallocation failed!\n");
        exit(1);
    }
}


void printArray(int* arr, int size) {
    printf("Package weights:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size, choice, index, weight;

    printf("Enter the initial number of packages: ");
    scanf("%d", &size);


    int* weights = createArray(size);


    printf("Enter weights for the initial packages:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &weights[i]);
    }

    do {
        printf("\nMenu:\n");
        printf("1. Insert a new package\n");
        printf("2. Delete a package\n");
        printf("3. Print package weights\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the index for insertion: ");
                scanf("%d", &index);
                printf("Enter the weight of the new package: ");
                scanf("%d", &weight);
                insert(weights, &size, index, weight);
                break;
            case 2:
                printf("Enter the index for deletion: ");
                scanf("%d", &index);
                delete(weights, &size, index);
                break;
            case 3:
                printArray(weights, size);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);


    free(weights);

    return 0;
}