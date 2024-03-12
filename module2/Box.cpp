/** Program to demonstrate Generic Class.
@author Anita Rathi
*/

#include <iostream>
#include<stdexcept>

using namespace std;

/** Generic class which data member of generic type 
*/

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

/** Box class objects of long type and string type are 
created in main().
*/

int main(){
  Box<long> longBox;
  Box<string> stringBox;

  longBox.setItem(769);
  stringBox.setItem("California");
  cout<<"Item of longBox = "<< longBox.getItem()<<endl;
  cout<<"Item of longBox = "<< stringBox.getItem()<<endl;
}