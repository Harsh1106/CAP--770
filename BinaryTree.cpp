/*
Binary Tree has e5 types:
1. Full Binary Tree: either has 0 or 2 children.
2. Complete Binary Tree: all levels are completely filled except the last level  and the last level has all nodes in left as possible.
3. Perfect Binary Tree: all leaf nodes are at same level.
4 Balanced Binary Tree: height of tree at maximum log(n). n -> number of nodes
5. Degenrate Tree: skew trees. in specific direction.
*/

// Creation of binary tree.
#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node* insertBST(Node* root, int val){
    if(root == NULL){
        return new Node(val);
    }
    if(val < root -> data){
        root -> left = insertBST(root -> left, val);
    }
    else{
        root -> right = insertBST(root -> right, val);
    }
    return root;
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root -> left);
    cout<<root -> data<<" ";
    inorder(root -> right);
}

int main(){
    Node* root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);

    //print 
    inorder(root);
    cout<<endl;
    return 0;
}