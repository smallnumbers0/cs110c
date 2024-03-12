#include <iostream>

using namespace std;

void countingSort(int arr[], int size, int& arrayAccesses) {
    const int SIZE = 100; 
    int count[SIZE] = {0}; 

   
    for (int i = 0; i < size; i++) {
        arrayAccesses++; 
        count[arr[i]]++;
      
    }

    
    int index = 0;
    for (int i = 0; i < SIZE; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
            arrayAccesses += 1; 
        }
    }
}

int main() {
    int arr[] = {71, 99, 3, 5, 23, 2, 91, 76, 71, 99, 3, 5, 23, 2, 91, 76, 71, 99, 3, 5, 23, 2, 91, 76,71, 99, 3, 5, 23, 2, 91, 76, 71, 99, 3, 5, 23, 2, 91, 76, 71, 99, 3, 5, 23, 2, 91, 76, 71, 99, 3, 5, 23, 2, 91, 76,71, 99, 3, 5, 23, 2, 91, 76, 71, 99, 3, 5, 23, 2, 91, 76, 71, 99, 3, 5, 23, 2, 91, 76, 71, 99, 3, 5, 23, 2, 91, 76,71, 99, 3, 5, 23, 2, 91, 76, 71, 99, 3, 5, 23, 2, 91, 76, 71, 99, 3, 5, 23, 2, 91, 76, 71, 99, 3, 5, 23, 2, 91, 76,71, 99, 3, 5, 23, 2, 91, 76};
    int size = sizeof(arr) / sizeof(arr[0]);
    int arrayAccesses = 0;

    countingSort(arr, size, arrayAccesses);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Number of array accesses: " << arrayAccesses << endl;

    return 0;
}
