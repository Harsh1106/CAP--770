// Implementation of Binary Search Tree

#include <iostream>

using namespace std;

struct Node {
  int key;
  Node* left;
  Node* right;
};

// Function to create a new BST node
Node* newNode(int item) {
  Node* temp = new Node();
  temp->key = item;
  temp->left = temp->right = nullptr;
  return temp;
}

// Function to perform inorder traversal of the BST
void inorder(Node* root) {
  if (root != nullptr) {
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
  }
}

// Function to insert a new node with the given key in the BST
Node* insert(Node* node, int key) {
  // If the tree is empty, return a new node
  if (node == nullptr) {
    return newNode(key);
  }

  // Recurse down the tree based on the key comparison
  if (key < node->key) {
    node->left = insert(node->left, key);
  } else if (key > node->key) {
    node->right = insert(node->right, key);
  }

  // Return the (unchanged) node pointer
  return node;
}

int main() {
  Node* root = nullptr;

  root = insert(root, 50);
  insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80);

  cout << "Inorder traversal: ";
  inorder(root);
  cout << endl;

  return 0;
}
