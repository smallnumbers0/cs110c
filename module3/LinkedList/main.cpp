//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

#include <iostream>
#include <string>
#include "LinkedList.h" // ADT list operations

using namespace std;

// void displayList(ListInterface<string>* listPtr)
// {
// 	cout << "The list contains " << endl;
//    for (int pos = 1; pos <= listPtr->getLength(); pos++)
//    {
//       cout << listPtr->getEntry(pos) << " ";
//    } // end for
// 	cout << endl << endl;
// }  // end displayList


int main()
{
   LinkedList<int> doublyLinkedList;

   
   doublyLinkedList.insert(1, 3);
   doublyLinkedList.insert(2, 6);
   doublyLinkedList.insert(3, 9);
   doublyLinkedList.insert(4, 50); 
   doublyLinkedList.insert(5, 50);

   cout << "Before Reverse: ";
   for (int i = 1; i <= doublyLinkedList.getLength(); i++) {
      cout << doublyLinkedList.getEntry(i) << " ";
   }
   cout <<endl;
   doublyLinkedList.reverse();

   cout << "Afer Reverse: ";
   for (int i = 1; i <= doublyLinkedList.getLength(); i++) {
      cout << doublyLinkedList.getEntry(i) << " ";
   }
   cout <<endl;
   return 0;
} 

/*
Sample output:
jackychoi@Jackys-MacBook-Pro LinkedList % ./a.out
Before Reverse: 3 6 9 50 50 
Afer Reverse: 50 50 9 6 3 
jackychoi@Jackys-MacBook-Pro LinkedList % 
*/