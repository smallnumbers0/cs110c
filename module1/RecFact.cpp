/** Program to compute the factorial of a non negative  integer n, using a recursive function.
  The program demonstartes a Value Returning Recursive function.
  Author - Anita Rathi
*/


#include<iostream>
using namespace std;

/** Calculates the factorial of a non negative integer n.
@ pre n should be greater than equal to 0.
@ post Returns the factorial of integer n.  
*/
int fact(int); 


int main(){
    int num;
    cout<<" Enter a number - ";
    cin>>num;
    cout<<"Factorial of "<< num << " = " << fact(num)<<endl;
    return 0;
}

/** Calculates the factorial of a non negative integer n.
@ pre n should be greater than equal to 0;
@ post Returns the factorial of integer n.  
*/
int fact(int n){
  if(n==0)//base case
    return 1;
  else{
    return (n * fact(n-1)); // calling the function for n-1
  }
}