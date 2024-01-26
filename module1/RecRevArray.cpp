/** Program to display a numeric array in reverse order, using a recursive function.
  The program demonstartes a Void Recursive function.
  Author - Anita Rathi
*/


#include<iostream>
using namespace std;

/** Displays a numeric array in reverse order.
@ pre Array should not be blank.
@ post The numeric array is dispalyed in reverse order.  
*/
void displayBackwards(int [], int); // Array and the size of the array are the parameters

/** Takes the input of a numeric array.
@ pre Array size should not be 0.
@ post The numeric array is filled with user input.  
*/
void input(int [], int); // Array and the size of the array are the parameters

/** Dispalys the elements in a numeric array.
@ pre Array size should not be 0.
@ post The numeric array is dispalyed.  
*/
void display(int [], int); // Array and the size of the array are the parameters

int main(){
    int A[10], n;
    //Loop for validation of the input for the number of elements in the array
    do{
      cout<<" Enter the number of elements in the array(<=10 and >0) - ";
      cin>>n;
    }while((n>10) || (n<1));
    input(A,n);//Calling input() 
    cout<<"The numbers in the array are =>"<<endl;
    display(A,n);
    cout<<"Numbers in  the array in the reverse order => "<<endl;
    displayBackwards(A,n);
    return 0;
}

/** Displays a numeric array in reverse order.
@ pre Array should not be blank.
@ post The numeric array is dispalyed in reverse order.  
*/
void displayBackwards(int A[], int n){
  if(n==0)//base case
    cout<<endl;
  else{
    cout<<A[n-1]<<" "; //displaying the last integer in the array
    n= n-1; //logically decreasing the size of the array by 1
    displayBackwards(A,n) ;//calling the function with reduced length
  }
}

/** Takes the input of a numeric array.
@ pre Array size should not be 0.
@ post The numeric array is filled with user input.  
*/
void input(int A[], int n){ // Array and the size of the array are the parameters
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
*/
void display(int A[], int n){ // Array and the size of the array are the parameters
  if(n<=0)
    cout<<"The array has size 0"<<endl;
  else{
    for(int i=0; i<n; i++){//loop to display Array elements
      cout<<A[i]<<" ";
    }
     cout<<endl;
  }
}





