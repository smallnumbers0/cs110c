#include <iostream>
using namespace std;

class Node {
    private:

    public:
        int data;
        Node* head;
        Node* next;

        Node(int value) : data(value), head(nullptr), next(nullptr) {}
        Node() {};

        int countList(Node* head) {
            //check if there are any items
            if(!head) {
                return 0;
            }
            //cycle through until head is found
            else {
                int count = 1;
                Node* temp = head->next;

                while (temp != head) {
                    count++;
                    temp = temp->next;
                }
                return count;
            }
        }
};    