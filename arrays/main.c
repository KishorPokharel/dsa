#include<stdio.h>
#define ARR_SIZE 100

void print_array(int arr[], int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

void insert(int arr[], int pos, int element, int* size) {
    if (*size >= ARR_SIZE) {
        printf("[!] array is full");
        return;
    }

    for (int i = *size - 1; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }
    arr[pos] = element;
    *size = *size + 1;
}

void delete(int arr[], int pos, int *size) {
    for (int i = pos; i < *size; i++) {
        arr[i] = arr[i+1];
    }
    *size = *size - 1;
}

void update(int arr[], int pos, int element) {
    if (pos >= ARR_SIZE) {
        fprintf(stderr, "[!] index can not be greater than size of array");
        return;
    }
    arr[pos] = element;
}

int main() {
    int arr[ARR_SIZE], size = 0, pos;
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;
    size = 5;

    print_array(arr, size);
    insert(arr, 2, 4, &size);
    print_array(arr, size);
    delete(arr, 2, &size);
    print_array(arr, size);
    update(arr, 4, 6);
    print_array(arr, size);
    update(arr, 100, 20);
    
    return 0;
}

