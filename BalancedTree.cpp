// Given a binary tree, find if it is height balanced or not.

#include<iostream>
#include<queue>
#include<string>
#include<sstream>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 

class Solution{
    private:
    int height(struct Node* node) {
        if (node == NULL) {
            return 0;
        }
        int left = height(node->left);
        int right = height(node->right);
        int ans = max(left, right) + 1;
        return ans;
    }
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        if(root == NULL){
            return true;
        }
        bool left = isBalanced(root -> left);
        bool right = isBalanced(root -> right);
        bool diff = abs(height(root -> left) - height(root -> right)) <= 1;
        
        if(left && right && diff){
            return 1;
        }
        else{
            return false;
        }
    }
};

// Function to build a binary tree from string representation
Node* buildTree(const string& treeString) {
    if (treeString.empty())
        return nullptr;

    stringstream ss(treeString);
    string token;
    queue<Node*> q;
    ss >> token;
    Node* root = new Node(stoi(token));
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        if (!(ss >> token)) break;

        if (token != "N") {
            current->left = new Node(stoi(token));
            q.push(current->left);
        }

        if (!(ss >> token)) break;

        if (token != "N") {
            current->right = new Node(stoi(token));
            q.push(current->right);
        }
    }
    return root;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s, ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution obj;
        cout<<obj.isBalanced(root)<<endl;
    }
    return 0;
}