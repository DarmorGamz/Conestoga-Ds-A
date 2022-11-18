#include <iostream>

void insertionSort(int[], int);

int main(void) {
    int N = 20;
    int random[20];
    for(int i = 0; i < N; i++) {
        random[i] = rand() % 100 + 1;
        std::cout << random[i] << " ";
    }
    insertionSort(random, N);
    std::cout << std::endl;
    for (int i = 0; i < N; i++) {
        std::cout << random[i] << " ";
    }
}

void swap(int* xp, int* yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}