#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int capacity;
    int used;
} Array;

void create(Array *, int);
void traverse(Array *);
void insert(Array *, int, int); //Inserts at given index and shifts existing values to right side
void delete(Array *, int);
void set(Array *, int, int); //Sets value at given index or replaces existing value if there any
int get(Array *, int);

int main() {
    int capacity;
    // printf("Enter the capacity of the new array: ");
    // scanf("%d", &capacity);
    capacity = 5;
    Array *arr = malloc(sizeof(Array));
    if(arr == NULL) {
        printf("Memory allocation failed.");
        exit(1);
    }
    create(arr, capacity);
    insert(arr, arr->used, 11);
    insert(arr, arr->used, 22);
    insert(arr, arr->used, 33);
    insert(arr, arr->used, 44);
    set(arr, 2, 11);
    delete(arr, 2);
    traverse(arr);
    get(arr, 2);
    free(arr->data);
    free(arr);
    return 0;
}

void create(Array *arr, int capacity) {
    if (capacity <= 0) {
        printf("Invalid capacity for array.\n");
        exit(1);
    }
    arr->capacity = capacity;
    arr->used = 0;
    arr->data = malloc(capacity * sizeof(int));
    if(arr->data == NULL) {
        printf("Memory allocation failed.");
        exit(1);
    }
}

void traverse(Array *arr) {
    if(arr->used == 0) {
        printf("Array is empty.\n");
        return;
    }
    else {
        printf("Elements of the array:\n");
        for(int i = 0; i < arr->used; i++) {
            printf("%d ", arr->data[i]);
        }
    }
    printf("\n");
}

void insert(Array *arr, int index, int value) {
    if(arr->used >= arr->capacity) {
        printf("Array capacity is full. Insertion failed.\n");
        return;
    }
    else if(index > arr->used || index < 0) {
        printf("Given index is out of bounds.\n");
        return;
    }
    else {
        for(int i = arr->used; i > index; i--) {
            arr->data[i] = arr->data[i - 1];
        }
        arr->data[index] = value;
        arr->used++;
    }
}

void delete(Array *arr, int index) {
    if(index >= arr->used || index < 0) {
        printf("Given index is invalid.\n");
        return;
    }
    else {
        for(int i = index; i < arr->used - 1; i++) {
            arr->data[i] = arr->data[i + 1];
        }
        arr->used--;
    }
}

void set(Array *arr, int index, int value) {
    if(index >= arr->used || index < 0) {
        printf("Given index is invalid.\n");
        return;
    }
    else {
        arr->data[index] = value;
    }
}

int get(Array *arr, int index) {
    if(index >= arr->used || index < 0) {
        printf("Given index is invalid.\n");
        return 0;
    }
    else {
        return arr->data[index];
    }
}
