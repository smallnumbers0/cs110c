/** Program to search for a number in a numeric array using Binary Search 
  method using a recursive function. The array has ements sorted in ascending order.
  The program demonstartes a Value Returing Recursive function.
  Author - Anita Rathi
*/


#include<iostream>
using namespace std;

/** Searches a numeric array sorted in ascending order for a number
 using Binary Search Method.
@ pre Array should not be blank and have elements sorted in ascending order.
@pre  0 <= first, last <= SIZE – 1, where SIZE is the
    maximum size of the array, and anArray[first] <=
    anArray[first + 1] <= ... <= anArray[last].
 @post  anArray is unchanged and either anArray[index] contains
    the given value or index == –1.
 @param anArray  The array to search.
 @param first  The low index to start searching from.
 @param last  The high index to stop searching at.
 @param target  The value to find.
 @return  Either index, such that anArray[index] == target, or –1.*/

int binarySearch(int [], int,  int, int); 

/** Takes the input of a numeric array.
@ pre Array size should not be 0.
@ post The numeric array is filled with user input.  
@ param anArray  The array for taking input of numbers.
@ param n  The size of the array.
*/
void input(int [], int); // Array and the size of the array are the parameters

/** Dispalys the elements in a numeric array.
@ pre Array size should not be 0.
@ post The numeric array is dispalyed.
@ param anArray  The array to display.
@ param n  The size of the array.  
*/
void display(int [], int); // Array and the size of the array are the parameters


/** Sorts the elements in a numeric array in ascending order.
@ pre Array size should not be 0.
@ post The numeric array is sorted.  
@ param anArray  The array to sort.
@ param n  The size of the array.
*/
void sort(int [], int); // Array and the size of the array are the parameters


int main(){
    int A[10], n, target;
    //Loop for validation of the input for the number of elements in the array
    do{
      cout<<" Enter the number of elements in the array(<=10 and >0) - ";
      cin>>n;
    }while((n>10) || (n<1));
    input(A,n);//Calling input() 
    cout<<"The numbers in the array are =>"<<endl;
    display(A,n);
    sort(A,n);//calling sor() to sort the elements
    cout<<"The sorted numbers in the array are =>"<<endl;
    display(A,n);
    cout<<"Enter the number to searched in the array : ";
    cin>>target;
    int location = binarySearch(A,0,n-1,target);
    if (location == -1)
      cout<< target << " is not in present in the array"<<endl;
    else
      //location is always the index+1
      cout<< target << " is present in the array at location "<<(location+1)<<endl;
    return 0;
}

/** Searches a numeric array sorted in ascending order for a number
 using Binary Search Method.
@ pre Array should not be blank and have elements sorted in ascending order.
@pre  0 <= first, last <= SIZE – 1, where SIZE is the
    maximum size of the array, and anArray[first] <=
    anArray[first + 1] <= ... <= anArray[last].
 @post  anArray is unchanged and either anArray[index] contains
    the given value or index == –1.
 @param anArray  The array to search.
 @param first  The low index to start searching from.
 @param last  The high index to stop searching at.
 @param target  The value to find.
 @return  Either index, such that anArray[index] == target, or –1.*/
int binarySearch(int A[], int first, int last, int target){

  int mid= (first + last)/2; //finding the index in the middle of the target array
  if (first>last)
    return -1; //base case
  else if (target==A[mid])
    return mid; // target is found
  else if (target>A[mid])
    return binarySearch(A,mid+1,last,target);//limiting search to second half of array
  else if (target<A[mid])
    return binarySearch(A,0,mid-1,target); //limiting search to first half of array   
} 

/** Sorts the elements in a numeric array in ascending order.
@ pre Array size should not be 0.
@ post The numeric array is sorted.  
@ param anArray  The array to sort.
@ param n  The size of the array.
*/
void sort(int A[], int n){ 
  for(int i=0;i<n;i++){
    for(int j=0; j<n-1-i;j++)
      if(A[j]>A[j+1]){
        int temp=A[j];
        A[j]=A[j+1];
        A[j+1]=temp;
      }
  }
}

/** Takes the input of a numeric array.
@ pre Array size should not be 0.
@ post The numeric array is filled with user input.  
@ param anArray  The array for taking input of numbers.
@ param n  The size of the array.
*/
void input(int A[], int n){ 
  if(n<=0)
    cout<<"The array has size 0"<<endl;
  else{
    for(int i=0; i<n; i++){//loop to take input of Array elements
      cout<<"Enter element "<< i+1 <<" : ";
      cin>>A[i];
    }
  }
}

/** Dispalys the elements in a numeric array.
@ pre Array size should not be 0.
@ post The numeric array is dispalyed.
@ param anArray  The array to display.
@ param n  The size of the array.  
*/
void display(int A[], int n){ 
  if(n<=0)
    cout<<"The array has size 0"<<endl;
  else{
    for(int i=0; i<n; i++){//loop to display Array elements
      cout<<A[i]<<" ";
    }
     cout<<endl;
  }
}





