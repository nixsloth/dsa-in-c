//The program assumes the given array to be sorted.
//If a search value has duplicate occurrences in the array, it returns only the first matching index that's found.

#include <stdio.h>

int binarySearch(int array[], int length, int value);

int main() {
    int array[] = {11, 22, 33, 44, 55, 66};
    int length = sizeof(array)/sizeof(array[0]);
    int value;
    printf("Enter the value to be searched: ");
    scanf("%d", &value);
    int index = binarySearch(array, length, value);
    if (index == -1) {
        printf("Given value not found in the array.\n");
    }
    else {
        printf("Value found at index %d.\n", index);
    }
    return 0;
}

int binarySearch(int array[], int length, int value) {
    int lower = 0, upper = length - 1;
    while (lower <= upper) {
        int mid = (lower + upper) / 2;
        if (array[mid] == value) {
            return mid;
        }
        else if (array[mid] > value) {
            upper = mid - 1;
        }
        else {
            lower = mid + 1;
        }
    }
    return -1;
}
