//Hopefully I am doing this correctly. The directions seem a little vague to me for where to put the exception, but I left it in the main function
//Graded Participation 2
//CS110C Jacky Choi
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

template <class ItemType>
class Box{
private:
    ItemType item;
public:
    
    void setItem(const ItemType &x){
      item = x;
    }
    
    ItemType getItem() const{
      return item;  
    }
};

template <class ItemType>
Box<ItemType> findBox(Box<ItemType> B[], int size, Box<ItemType> target) {
    int i = 0;
    bool found = false;

    while(i<size && !found) {
        if(B[i].getItem() == target.getItem()) {
            found=true;
        }
        else {
          i++;
        }
    }
    if(!found) {
      throw logic_error("Element not present in the array");  //throwing exception
    }
    return(B[i]);
}

int main() {

    Box<int> B[5];
    Box<int> target,resultBox;
    int num;
    B[0].setItem(204352);
    B[1].setItem(293482);
    B[2].setItem(199201);
    B[3].setItem(324123);
    B[4].setItem(219101); 
    cout<<"Enter a positive integer: ";
    cin>>num;

    //Addding throw exception to stop negative numbers.
    if (num < 0) {
        throw logic_error("Entered number cannot be negative");
    }
    /*********************************************************/
    target.setItem(num);

    try{
        resultBox = findBox(B,5,target);
        cout<< resultBox.getItem() << " present in the array."<<endl;
    }
    catch(logic_error le){
        cout<<le.what()<< endl;
    }
    return 0;
}


/*
jackychoi@Jackys-MacBook-Pro module2 % g++ Exception1.cpp
jackychoi@Jackys-MacBook-Pro module2 % ./a.out           
Enter a positive integer: -123456
libc++abi: terminating due to uncaught exception of type std::logic_error: Entered number cannot be negative
zsh: abort      ./a.out
jackychoi@Jackys-MacBook-Pro module2 % ./a.out           
Enter a positive integer: 204352
204352 present in the array.
jackychoi@Jackys-MacBook-Pro module2 % ./a.out
Enter a positive integer: 123456
Element not present in the array
jackychoi@Jackys-MacBook-Pro module2 % 
*/