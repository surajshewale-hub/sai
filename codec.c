#include<stdio.h>
#include<stdlib.h>
int* createArr(int size){
    int *arr = (int*) malloc(size*sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    return arr;
}

void insert(int *arr,int *size,int index,int weight){
    if(index < 0 || index > *size){
        printf("Invalid index for insertion!\n");
        return;
    }

    (*size)++;
    arr = (int*)realloc(arr,*size * sizeof(int));

    if(arr == NULL){
        printf("MEMORY ALLOCATION IS FAILED..");
        return;
    }

    for(int i = *size-1;i> index;i--){
        arr[i] = arr[i-1];

    }

    arr[index] = weight; 
}

void delete(int *arr,int *size,int index){
    if (index < 0 || index >= *size) {
        printf("Invalid index for deletion!\n");
        return;
    }

    for(int i = index;i< *size-1;i++){
        arr[i] = arr[i+1];
    }
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
int main(){
    int size, choice, index, weight;

    printf("Enter the initial number of packages: ");
    scanf("%d", &size);


    int* weights = createArr(size);


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

    return 0;
}