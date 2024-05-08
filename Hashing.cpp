/*#include <iostream>
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
*/

// hashing through STL
#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
  unordered_map<string, int> m;

  // 1st way to create hashmap
  pair<string, int> p = make_pair("harsh", 3);
  m.insert(p);

  // 2nd way to create hashmap
  pair<string, int> p2("raj", 2);
  m.insert(p2);
  
  // 3rd way to create hashmap
  m["mera"] = 1;


  // searching
  cout<<m["mera"]<<endl;
  cout<<m.at("harsh")<<endl;

  cout<<m["unknownKey"]<<endl;
  cout<<m.at("unknownKey")<<endl;

  cout<<m.size()<<endl;

  cout<<m.count("harsh")<<endl;

  m.erase("harsh");
  cout<<m.size()<<endl;


  return 0;
}