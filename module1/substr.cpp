#include <iostream>
using namespace std;

int main() {

    string exampleString = "Hello";
    string subString = exampleString.substr(0,3); //Starting at position 0 of "Hello", get a string of length 3
    cout<<subString<<endl; //This prints out "Hel"
    return 0;
}