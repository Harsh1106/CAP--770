/*
There are 3 modes of traversal:
1. Inorder Traversal: Left Root Right
2. Pre-order Traversal: Root Left Right
3. Post-Order Traversal: Left Right Root
*/

#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *left, *right;
    node(int data){
        this -> data = data;
        left = right = NULL;
    }
};

void preorder(node* root){
    // TC: O(n)
    // SC: O(n)
    if(root == NULL){
        return;
    }
    cout<<root -> data<<" ";
    preorder(root -> left);
    preorder(root -> right);
}

void inorder(node*  root){
    if(root == NULL){
        return;
    }
    inorder(root -> left);
    cout<<root -> data<<" ";
    inorder(root -> right);
}

void postorder(node* root){
    if(root == NULL){
        return;
    }
    postorder(root -> left);
    postorder(root -> right);
    cout<<root -> data<<" ";
}

int main(){
    struct node* root = new node(1);
    root -> left = new node(2);
    root -> left -> left = new node(4);
    root -> left -> right = new node(5);
    root -> left -> right -> left = new node(6);
    root -> right = new node(3);
    root -> right -> left = new node(7);
    root -> right -> right = new node(8); 
    // root -> right -> left = new node(9);
    // root -> right -> right = new node(10);

    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);

    return 0;
}