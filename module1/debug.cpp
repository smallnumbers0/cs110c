#include<iostream>
#include<string>
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
        displayBackwards(s.substr(pos)); 
        //recursive calls: ello -> llo -> lo -> o, prints: o -> l -> l -> e -> h
        cout << s[0]; 
    }
}