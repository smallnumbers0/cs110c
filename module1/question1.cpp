//This program reverses a string
//CS110C JAcky Choi

#include<iostream>
using namespace std;

void displayBackwards(string); 

int main(){
    string s;
    cout<<"Enter a string - ";
    cin>>s;
    cout<<"Reverse of string "<< s << " = "<<endl;
    displayBackwards(s);
    cout<<endl; //added to clean up % from ym output
    return 0;
}

void displayBackwards(string s){
    int length = s.size();

    //Base case stopping
    if(length == 0) {
        return;
    }
    else {
        cout<<"displayBackwards("<<s.substr(1, length - 1)<<")"<<endl;
        displayBackwards(s.substr(1, length - 1)); 
        //recursive calls: ello -> llo -> lo -> o, prints: o -> l -> l -> e -> h
        cout << s[0]; 
    }
}

/*
jackychoi@Jackys-MacBook-Pro module1 % g++ question1.cpp
jackychoi@Jackys-MacBook-Pro module1 % ./a.out          
Enter a string - hello
Reverse of string hello = 
displayBackwards(ello)
displayBackwards(llo)
displayBackwards(lo)
displayBackwards(o)
displayBackwards()
olleh
jackychoi@Jackys-MacBook-Pro module1 % 
*/