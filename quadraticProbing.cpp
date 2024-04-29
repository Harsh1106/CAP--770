#include<iostream>

#define size 10

using namespace std;

int h[size] = {NULL};

void insert(){
    int key, index, i, flag = 0, hkey;

    cout << "\nEnter a value to insert into hash table\n";
    cin >> key;
    hkey = key % size; 
    for (i = 0; i < size; i++) {
        index = (hkey + i*i) % size; 
        if (h[index] == NULL) {
        h[index] = key;
        cout << "Element inserted at index " << index << endl;
        break;
        }
    }
    if (i == size) {
        cout << "\nElement cannot be inserted (Hash Table Overflow)\n";
    }
}

void search(){
    int key, index, i, flag = 0, hkey;
    cout<<"Enter the searching element: "<<endl;
    cin>>key;
    hkey = key % size;
    for (i = 0; i < size ; i++) {
    index = (hkey + i*i) % size;
    if (h[index] == key) {
      cout << "Value found at index " << index << endl;
      break;
    } else if (h[index] == NULL) {  
      cout << "\nValue is not found\n";
      break;
    }
  }
  if (i == size && h[index] != key) { 
    cout << "\nValue is not found\n";
  }
}

void display() {
  int i;

  cout << "\nElements in the hash table are \n";

  for (i = 0; i < size; i++) {
    cout << "\nat index " << i << " \t value = ";
    if (h[i] == NULL) {
      cout << "NULL";
    } else {
      cout << h[i];
    }
    cout << endl;
  }
}

int main(){
    int opt, i;

    while (1) {
        cout << "\nPress 1. Insert\t 2. Display \t3. Search \t4.Exit \n";
        cin >> opt;
        switch (opt) {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            search();
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice\n";
        }
    }
}