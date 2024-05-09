#include<iostream>
using namespace std;

struct node{
    int data;
    node* right;
    node* left;
    node(int data){
        this -> data = data;
        right = NULL;
        left = NULL;
    }
};
class tree{
    public:
        node* searchBST(node* root, int val){
            while(root != NULL && root -> data != val){
                root = val<root -> data ? root -> left : root -> right;
            }
            return root;
        }
        node* insertion(node* root, int val){
            if(root == NULL){
                return new node(val);
            }
            if(root -> data > val){
                root -> left = insertion(root -> left, val);
            }
            else{
                root -> right = insertion(root -> right, val);
            }
            return root;
        }
};

int main(){
    node* root = NULL;
    tree t;
    int num;
    cout<<"Enter the number of times you want to insert data: "<<endl;
    cin>>num;
    for(int i = 0 ; i < num ; i++){
        cin>>num;
        root = t.insertion(root, num);
    }
    cout<<"Enter the value you want to search in tree: ";
    int search;
    cin>>search;
    root = t.searchBST(root, search);
    cout<<root -> data;

    return 0;
}