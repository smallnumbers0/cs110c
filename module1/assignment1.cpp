//Assignment1 homework
//CS110C Jacky Choi


#include <iostream>
using namespace std;

//Ch 2 Exercise 9: Recursive function that reverses the digits of a positive decimal integer
void reverseDigits(int num) {
    if(num == 0) {
        return;
    }
    else {
        cout<<num % 10;
        reverseDigits(num / 10);
    }
}

//Ch2 pg 61 writeBackward functions: Reversing string with 2 different ways
void writeBackward(string s) {
    int length = s.size();
    cout << "Enter writeBackward with string: " << s << endl;
    if(s == "") {
        return;
    }
    else {
        cout<<"About to write the last character: "<<s[length-1]<<endl;
        writeBackward(s.substr(0,length-1));
    }
    cout << "Leave writeBackward with string: " << s << endl;
}

void writeBackward2(string s) {
    int length = s.size();
      cout << "Enter writeBackward2 with string: " << s << endl;
    if(s == "") {
        return;
    }
    else {
        writeBackward2(s.substr(1, length-1));
        cout<<"About to write the first character: "<<s[0]<<endl;
    }
    cout << "Leave writeBackward2 with string: " << s << endl;
}

//Chapter 2, exercise 4: Given two integers, start and end, where end is greater than start, write a recursive C++ function that returns the sum of the integers from start through end, inclusive.  For example, if start is 3 and end is 6, the function should return 18, because 3+4+5+6 = 18.

int recursiveSum(int a, int b) {
    cout<<"This is value of a for this call: "<<a<<" and this is b: "<<b<<endl;
    if(a == b) {
        return a;
    }
    else {
        return a + recursiveSum(a+1, b);
        
    }
}


int main() {
    int num;
    cout<<"Please enter a positive integer: ";
    cin>>num;
    cout<<"The reverse of "<<num<<" is ";
    reverseDigits(num);
    cout<<"."<<endl;

    cout<<"Testing writeBackward function:"<<endl;
    string s;
    cout<<"Enter a string: ";
    cin>>s;
    cout<<"The reverse of "<<s<<" is "<<endl;
    writeBackward(s);
    cout<<endl;

    cout<<"Testing writeBackward2 function:"<<endl;
    string s2;
    cout<<"Enter a string: ";
    cin>>s2;
    cout<<"The reverse of "<<s2<<" is "<<endl;
    writeBackward2(s2);
    cout<<endl;

    cout<<"Testing recursiveSum function:"<<endl;
    int a = 3;
    int b = 6;
    int c = recursiveSum(a,b);
    cout<<c<<endl;
    


    return 0;
}

/*
jackychoi@Jackys-MacBook-Pro module1 % g++ assignment1.cpp
jackychoi@Jackys-MacBook-Pro module1 % ./a.out            
Please enter a positive integer: 123456
The reverse of 123456 is 654321.
Testing writeBackward function:
Enter a string: hello
The reverse of hello is 
Enter writeBackward with string: hello
About to write the last character: o
Enter writeBackward with string: hell
About to write the last character: l
Enter writeBackward with string: hel
About to write the last character: l
Enter writeBackward with string: he
About to write the last character: e
Enter writeBackward with string: h
About to write the last character: h
Enter writeBackward with string: 
Leave writeBackward with string: h
Leave writeBackward with string: he
Leave writeBackward with string: hel
Leave writeBackward with string: hell
Leave writeBackward with string: hello

Testing writeBackward2 function:
Enter a string: hello
The reverse of hello is 
Enter writeBackward2 with string: hello
Enter writeBackward2 with string: ello
Enter writeBackward2 with string: llo
Enter writeBackward2 with string: lo
Enter writeBackward2 with string: o
Enter writeBackward2 with string: 
About to write the first character: o
Leave writeBackward2 with string: o
About to write the first character: l
Leave writeBackward2 with string: lo
About to write the first character: l
Leave writeBackward2 with string: llo
About to write the first character: e
Leave writeBackward2 with string: ello
About to write the first character: h
Leave writeBackward2 with string: hello

Testing recursiveSum function:
This is value of a for this call: 3 and this is b: 6
This is value of a for this call: 4 and this is b: 6
This is value of a for this call: 5 and this is b: 6
This is value of a for this call: 6 and this is b: 6
18
jackychoi@Jackys-MacBook-Pro module1 % 
*/