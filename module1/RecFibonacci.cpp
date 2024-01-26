/** Program to generates nth fibonacci non negative integer. using a recursive function.
  The program demonstartes a Value Returning Recursive function.
  Author - Anita Rathi
*/


#include<iostream>
using namespace std;

/** Generates a fibonacci non negative integer n.
@ pre n should be greater than equal to 0;
@ post returns nth fibonacci number.  
@ param n a non negative integer
*/
int fib(int); 


int main(){
    int num;
    cout<<" Enter a number - ";
    cin>>num;
    cout<<num << " fibonacci number is  "<< fib(num)<<endl;
    return 0;
}

/** Generates nth fibonacci non negative integer.
@ pre n should be greater than equal to 0;
@ post returns nth fibonacci number.  
@ param n a non negative integer
*/
int fib(int n){
  if(n<=0)//base case
    return 0;
  else if(n==1)
    return 0;
  else if(n==2) // base case
    return 1; 
  else
    return fib(n-1) + fib(n-2); // calling the function for n-1 and n-2
  }
