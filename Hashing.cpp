#include <iostream>
#include <vector>

using namespace std;

#define size 7

struct Node {
  int data;
  Node* next;
};

vector<Node*> chain(size, nullptr);

void init() {
  for (int i = 0; i < size; i++) {
    chain[i] = nullptr;
  }
}

void insert(int value) {
  Node* newNode = new Node;
  newNode->data = value;
  newNode->next = nullptr;
  int key = value % size;
  if (chain[key] == nullptr) {
    chain[key] = newNode;
  } else {
    Node* temp = chain[key];
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

void search(int value){
    int key = value % size;
    Node* temp = chain[key];

    while(temp){
      if(temp -> data == value){
        cout<<"Data: "<<value<<" is found."<<endl;
        return;
      }
      temp = temp -> next;
    }
    cout<<"Data: "<<value<<" is not found."<<endl;
}

void print() {
  for (int i = 0; i < size; i++) {
    Node* temp = chain[i];
    cout << "chain[" << i << "]-->";
    while (temp) {
      cout << temp->data << " -->";
      temp = temp->next;
    }
    cout << "NULL\n";
  }
}

int main() {
  init();

  insert(7);
  insert(49);
  insert(0);
  insert(3);
  insert(10);
  insert(4);
  insert(5);

  print();

  search(0);

  return 0;
}
