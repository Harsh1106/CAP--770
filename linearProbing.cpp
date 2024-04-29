#include <iostream>

#define size 10

using namespace std;

int h[size] = {NULL}; // Initialize hash table to NULL values

void insert() {
  int key, index, i, flag = 0, hkey;

  cout << "\nEnter a value to insert into hash table\n";
  cin >> key;

  hkey = key % size; // Calculate hash index

  // Probe for an empty slot using linear probing
  for (i = 0; i < size; i++) {
    index = (hkey + i) % size; // Calculate probed index

    if (h[index] == NULL) {
      h[index] = key;
      cout << "Element inserted at index " << index << endl;
      break;
    }
  }

  if (i == size) {  // Table full
    cout << "\nElement cannot be inserted (Hash Table Overflow)\n";
  }
}

void search() {
  int key, index, i, flag = 0, hkey;

  cout << "\nEnter search element\n";
  cin >> key;

  hkey = key % size;

  // Probe for the key using linear probing
  for (i = 0; i < size; i++) {
    index = (hkey + i) % size;
    if (h[index] == key) {
      cout << "Value found at index " << index << endl;
      break;
    } else if (h[index] == NULL) {  // Encountered an empty slot, key not found
      cout << "\nValue is not found\n";
      break;
    }
  }

  if (i == size && h[index] != key) { // Searched entire table, not found
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

int main() {
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
