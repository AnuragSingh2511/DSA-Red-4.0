#include<iostream>
using namespace std;

class Node{
    public:
     int data;
     Node* next;

     //Constructor
     Node(int value){
        this->data = value;
        this->next = NULL;
     }
};

void insertAtHead(int value, Node* &head, Node* &tail){
  
  if(head == NULL && tail == NULL){
    //empty ll
     Node* newNode = new Node(value);
     head = newNode;
     tail = newNode;
  }
  
  else{
     //non-empty ll
     Node* newNode = new Node(value);
     newNode->next = head;
     head = newNode;
  }
}

void insertAtTail(int value, Node* &head, Node* &tail){
    if(head == NULL && tail == NULL){
    //empty ll
     Node* newNode = new Node(value);
     head = newNode;
     tail = newNode;
  }
  
  else{
     //non-empty ll
     Node* newNode = new Node(value);
     tail->next = newNode;
     tail = newNode;
  }
}

void printLinkedList(Node* head){
  Node* temp = head;

  while(temp != NULL){
    cout << temp->data << "->";
    temp = temp->next;
  }
  cout << endl;
}

bool searchLinkedList(int target, Node* head){
    Node* temp = head;

    while(temp != NULL){
        if(temp->data == target){
            return true;
        }
        else{
            temp = temp->next;
        }
    }
    return false;
}

int main(){
   
    //Empty linked-list
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(10, head, tail);
    insertAtHead(20, head, tail);
    insertAtHead(30, head, tail);
    insertAtTail(40, head, tail);
    printLinkedList(head);
    
    cout << (searchLinkedList(10, head) ? "true" : "false");

    return 0;
}