//This program is a O(n^2) sorting algorithm called bubble sort
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size) {
    int count = 0;
    
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - 1; j++) {
            if(arr[j] < arr[j + 1]) {
                int max = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = max;
                count += 6;
            }
            else {
                count += 2;
            }
        }
    }
    cout<<count<<endl;
    for(int i = 0; i < size; i++) {
        cout<<arr[i] << ' ';
    }
}

int main() {
    const int SIZE = 128;
    int numsArr[SIZE] = {2, 12, 8, 13, 17, 99, 32, 35, 25, 12, 44, 13, 17, 99, 12, 14, 1, 12, 54, 13, 17, 99, 32, 43, 25, 12, 82, 13, 17, 99, 32, 43, 2, 12, 8, 13, 17, 99, 32, 35, 25, 12, 44, 13, 17, 99, 12, 14, 1, 12, 54, 13, 17, 99, 32, 43, 25, 12, 82, 13, 17, 99, 32, 43, 2, 12, 8, 13, 17, 99, 32, 35, 25, 12, 44, 13, 17, 99, 12, 14, 1, 12, 54, 13, 17, 99, 32, 43, 25, 12, 82, 13, 17, 99, 32, 43, 2, 12, 8, 13, 17, 99, 32, 35, 25, 12, 44, 13, 17, 99, 12, 14, 1, 12, 54, 13, 17, 99, 32, 43, 25, 12, 82, 13, 17, 99, 32, 43};
    cout<<"Array access count: "<<endl;
    bubbleSort(numsArr, 128);
  

    return 0;
}
