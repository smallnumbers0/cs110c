#include <iostream>
using namespace std;

int oddSum(int arr[], int size) {
    int sum = 0;
    if(size < 1) {
        return sum;
    }
    else {
        if(arr[size-1] % 2 == 1) {
            sum += arr[size - 1];
        }
        return sum + oddSum(arr, size - 1);
    }
}