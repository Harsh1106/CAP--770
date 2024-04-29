// implement the concept of binary search tree enter the values at runtime.
#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;

  Node(int data) {
    this->data = data;
    left = NULL;
    right = NULL;
  }
};

Node* insertData(Node* root, int val) {
  if (root == NULL) {
    return new Node(val);
  }

  if (val < root->data) {
    root->left = insertData(root->left, val);
  } else {
    root->right = insertData(root->right, val);
  }

  return root;
}

void display(Node* root) {
  if (root == NULL) {
    return;
  }

  display(root->left);
  cout << root->data << " ";
  display(root->right);
}

int main() {
  Node* root = NULL;
  int num;

  cout << "Enter the number of times of data you want to enter: ";
  cin >> num;

  int val;
  cout << "Enter the members of tree: ";

  for (int i = 0; i < num; i++) {
    cin >> val;
    root = insertData(root, val);
  }

  cout << "Values of tree: ";
  display(root);
  cout << endl;

  return 0;
}
