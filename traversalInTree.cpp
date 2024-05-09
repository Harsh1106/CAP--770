#include<iostream>
using namespace std;

struct node{
    int data;
    node* right;
    node* left;
    node(int val){
        this -> data = val;
        right = NULL;
        left = NULL;
    }
};
node* insertData(node* root, int val){
    if(root == NULL){
        return new node(val);
    }
    if(val < root -> data){
        root -> left = insertData(root -> left, val);
    }
    else{
        root -> right = insertData(root -> right, val);
    }
    return root;
}
void display(node* root){
    if(root == NULL){
        return;
    }
    // Preorder
    // cout<<root -> data<<" ";
    // display(root -> left);
    // display(root -> right);
    // Inorder
    // display(root -> left);
    // cout<<root -> data<<" ";
    // display(root -> right);
    // Postorder
    display(root -> left);
    display(root -> right);
    cout<<root -> data<<" ";
}
int main(){
    node* root = NULL;
    int val;
    cout<<"Enter the number of times you want to insert data: "<<endl;
    cin>>val;
    int num;
    for(int i = 0 ; i < val ; i++){
        cin>>num;
        root = insertData(root, num);
    }
    cout<<"Printing the tree: "<<endl;
    display(root);
}