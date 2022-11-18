#include <iostream>
void bubbleSort(int[], int);
void mergeSort(int arr[][8], int arr2[]);

int main() {
    int random[3][8];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 8; j++) {
            random[i][j] = rand() % 100 + 1;
            std::cout << random[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;


    
    for (int i = 0; i < 3; i++) {
        bubbleSort(random[i], 8);
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 8; j++) {
            std::cout << random[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;

    int arr2[24];
    mergeSort(random, arr2);
}

void swap(int* xp, int* yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already
        // in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void mergeSort(int arr[][8], int arr2[]) {
    int i = 0;
    while (i < 24) {
        int temp = 1000000; int tempi = 0; int tempj = 0;
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 8; k++) {
                if(arr[j][k] != NULL) {
                    if (arr[j][k] < temp) {
                        temp = arr[j][k];
                        tempi = j; tempj = k;
                    }
                }
            }
        }
        arr2[i] = temp;
        arr[tempi][tempj] = NULL;
        i++;
    }
    for (int i = 0; i < 24; i++) {
        std::cout << arr2[i] << " ";
    }
}