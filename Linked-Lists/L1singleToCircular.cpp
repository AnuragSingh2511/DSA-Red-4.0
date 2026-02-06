#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Convert Singly Linked List to Circular Linked List
// T.C = O(n), S.C = O(1)
void makeCircular(Node* head) {
    if(head == NULL) return;

    Node* temp = head;

    // go to last node
    while(temp->next != NULL) {
        temp = temp->next;
    }

    // connect last node to head
    temp->next = head;
}

// Print Circular Linked List (print once)
void printCircular(Node* head) {
    if(head == NULL) return;

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while(temp != head);
}

int main() {
    // Creating singly linked list: 10 -> 20 -> 30 -> NULL
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    makeCircular(head);

    cout << "Circular Linked List: ";
    printCircular(head);

    return 0;
}
