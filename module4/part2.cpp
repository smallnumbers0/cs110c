#include <iostream>
using namespace std;

template<class ItemType>
int sortFirstMiddleLast(ItemType theArray[], int first, int last) {
    int mid = (first + last) / 2;
    int count = 0;
    if (theArray[first] > theArray[mid]) {
        swap(theArray[first], theArray[mid]);
        count += 4;
        
    }
    if (theArray[first] > theArray[last]) {
        swap(theArray[first], theArray[last]);
        count += 4;
    }
    if (theArray[mid] > theArray[last]) {
        swap(theArray[mid], theArray[last]);
        count += 4;
    }
   
    cout<<"Array Acess Count: " << count <<endl;
    return mid;
}

template<class ItemType>
int partition(ItemType theArray[], int first, int last) {
    int pivotIndex = sortFirstMiddleLast(theArray, first, last);
    int count = 0;
    swap(theArray[pivotIndex], theArray[last - 1]);
    pivotIndex = last - 1;
    ItemType pivot = theArray[pivotIndex];

    int indexFromLeft = first;
    int indexFromRight = last - 2;

    while (true) {
        while (theArray[indexFromLeft] < pivot) {
            indexFromLeft++;
        }
        while (indexFromRight >= first && theArray[indexFromRight] > pivot) {
            indexFromRight--;
        }
        if (indexFromLeft < indexFromRight) {
            swap(theArray[indexFromLeft], theArray[indexFromRight]);
            indexFromLeft++;
            indexFromRight--;
            count += 2;
        } else {
            break;
        }
    }
    swap(theArray[pivotIndex], theArray[indexFromLeft]);
    count += 2;
    pivotIndex = indexFromLeft;
    cout << "Array Access Count: " << count << endl;
    return pivotIndex;
}


template<class ItemType>
void quicksort(ItemType theArray[], int first, int last) {
    if (first < last) {
        int pivotIndex = partition(theArray, first, last);
        quicksort(theArray, first, pivotIndex - 1);
        quicksort(theArray, pivotIndex + 1, last);
    }
}

int main() {
    const int SIZE = 128;
    int numsArr[SIZE] = {2, 12, 8, 13, 17, 99, 32, 35, 25, 12, 44, 13, 17, 99, 12, 14, 1, 12, 54, 13, 17, 99, 32, 43, 25, 12, 82, 13, 17, 99, 32, 43, 2, 12, 8, 13, 17, 99, 32, 35, 25, 12, 44, 13, 17, 99, 12, 14, 1, 12, 54, 13, 17, 99, 32, 43, 25, 12, 82, 13, 17, 99, 32, 43, 2, 12, 8, 13, 17, 99, 32, 35, 25, 12, 44, 13, 17, 99, 12, 14, 1, 12, 54, 13, 17, 99, 32, 43, 25, 12, 82, 13, 17, 99, 32, 43, 2, 12, 8, 13, 17, 99, 32, 35, 25, 12, 44, 13, 17, 99, 12, 14, 1, 12, 54, 13, 17, 99, 32, 43, 25, 12, 82, 13, 17, 99, 32, 43};
    quicksort(numsArr, 0, SIZE - 1);
    
    cout << "Sorted array: ";
    for (int i = 0; i < SIZE; ++i) {
        cout << numsArr[i] << " ";
    }
    cout << endl;

    return 0;
}
