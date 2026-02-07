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

int lengthLinkedList(Node* head){
    Node* temp = head;
    int len = 0;

    while(temp != NULL){
        len++;
        temp = temp -> next;
    }
    return len;
}

void insertAtPosition(int position, int value, Node* &head, Node* &tail){
  //assuming given position will be inside bounds and not invalid

  //checking out of bound position
  //valid range -> 1 to length + 1
  int len = lengthLinkedList(head);
  if(position < 1 || position > len + 1){
    return;
  }
  
  if(position == 1){
    insertAtHead(value, head, tail);
    return;
  }

  

  if(position == len + 1){
    insertAtTail(value, head, tail);
    return;
  }
  else{
    //step 1: create node
    Node* newNode = new Node(value);
    //step 2: temp ko pos - 1 reach karwao
    Node* temp = head;
    for(int i = 0; i <= position - 1; i++){
        temp = temp -> next;
    }
    //step 3: newNode ko link with aage ka node
    newNode->next = temp->next;
    // step 4: update temp->next
    temp->next = newNode;
  }
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

    insertAtPosition(2, 20, head, tail);
    printLinkedList(head);
    
    

    return 0;
}