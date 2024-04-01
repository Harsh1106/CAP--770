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



int main(){
    struct Node *root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> right = new Node(5);
    return 0;
}