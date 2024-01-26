/** Program to display the reverse of a non blank string s , using a recursive function.
  The program demonstartes a Void Recursive function.
  Author - Anita Rathi
*/


#include<iostream>
using namespace std;

/** Displays the reverse of a non blank string s.
@ pre s should not be blank.
@ post The reverse of the string s is dispalyed.  
*/
void displayBackwards(string); 


int main(){
    string s;
    cout<<" Enter a string - ";
    cin>>s;
    cout<<"Reverse of string "<< s << " = ";
    displayBackwards(s);
    return 0;
}

/** Displays the reverse of a non blank string s.
@ pre s should not be blank.
@ post The reverse of the string s is dispalyed.  
*/
void displayBackwards(string s){
  int length = s.size();
  if(length==0)//base case
    cout<<endl;
  else{
    cout<<s[s.size()-1]; //displayeng the last character in the string
    displayBackwards(s.substr(0,length-1));//calling the function with reduced string
  }
}