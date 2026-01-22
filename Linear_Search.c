//If a search value has duplicate occurrences in the array, it returns only the first occurance.

#include <stdio.h>

int linearSearch(int array[], int length, int value);

int main() {
    int array[] = {99, 22, 11, 55, 33};
    int length = sizeof(array)/sizeof(array[0]);
    int value;
    printf("Enter the value to be searched: ");
    scanf("%d", &value);
    int index = linearSearch(array, length, value);
    if(index == -1) {
        printf("Value not found in the array.\n");
    }
    else {
        printf("Value found at index %d.\n", index);
    }
    return 0;
}

int linearSearch(int array[], int length, int value) {
    for(int i = 0; i < length; i++) {
        if(array[i] == value) {
            return i;
        }
    }
    return -1;
}
