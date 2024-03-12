#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* head;
    Node* next;

    Node(int value) : data(value), head(nullptr), next(nullptr) {}
    Node() {};

    int countList(Node* head) {
        //check if there are any items
        if (!head) {
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

int main() {
    // Create some nodes
    Node* node1 = new Node(5);
    Node* node2 = new Node(3);
    Node* node3 = new Node(9);

    // Link them in a circular fashion
    node1->next = node2;
    node2->next = node3;
    node3->next = node1;

    // Now, node1 acts as the head of the circular linked list
    Node* head = node1;

    // Create an instance of the Node class
    Node node;

    // Call the countList function on the instance
    int count = node.countList(head);

    // Print the count
    cout << "Number of items in the circular linked list: " << count << endl;

    // Free allocated memory
    delete node1;
    delete node2;
    delete node3;

    return 0;
}
