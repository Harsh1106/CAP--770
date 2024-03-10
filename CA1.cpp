#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node(int data){
            this -> data = data;
            this -> next = NULL;
        }
};

void insertAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}

void printList(Node* head){
    Node* temp = head; 
    while(temp != NULL){
        cout<< temp -> data <<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main(){
    cout<<"Enter the choice: \n1. Enter 1 to insert data at head\n2. Enter 2 to insert data at back\n0. Exit"<<endl;
    int choice;
    cin>>choice;
    Node* head =  NULL;
    switch (choice)
    {
    case 1:
        int n;
        cout<<"Enter the data you want to insert in front: ";
        cin>>n;
        insertAtHead(head, n);
        printList(head);
        break;
    case 2:
        cout<<"Enter the data you want to insert in back: ";
        cin>>n;
        insertAtTail(head, n);
        printList(head);
        break;
    case 0: 
        cout<<"Exiting"<<endl;
    default:
        break;
    }
}