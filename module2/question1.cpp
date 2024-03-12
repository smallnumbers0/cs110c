

#include <iostream>
#include<stdexcept>

using namespace std;


template <class ItemType>
class Box{
private:
    ItemType item;
public:
    void setItem(const ItemType& x){
        item = x;
    }
    ItemType getItem() const{
        return item;
    }
};


int main(){
  Box<long> longBox;
  Box<string> stringBox;

  longBox.setItem(769);
  stringBox.setItem("California");
  cout<<"Item of longBox = "<< longBox.getItem()<<endl;
  cout<<"Item of longBox = "<< stringBox.getItem()<<endl;
}