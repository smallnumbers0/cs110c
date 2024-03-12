/** Program to demonstrate Generic Function.
@author Anita Rathi
*/


#include <iostream>

using namespace std;

/** Generic function which. takes three arguments of generic 
type, and return the. largest of three */

template <typename T >
T large(T x, T y, T z){
  if (x>=y && x>=z)
    return x;
  else if (y>=x && y>=z)
    return y;
  else
    return z;
} 

/** Generic Function large() is called with int type and double type.
*/
int main(){
  int a = 45,  b = 67, c = 50;
  double l = 5.7,  m = 6.8  , n = 5.1;
  cout<<"Largest of integers = "<< large(a,b,c)<<endl;
  cout<<"Largest of doubles = "<< large(l,m,n)<<endl;
}

