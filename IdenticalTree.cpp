// TC: O(N)

#include<iostream>
#include<sstream>
#include<queue>
#include<string>
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

   
class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        if(r1 == NULL && r2 == NULL){
            return true;
        }
        if(r1 == NULL && r2 != NULL){
            return false;
        }
        if(r1 != NULL && r2 == NULL){
            return false;
        }
        
        bool left = isIdentical(r1 -> left, r2 -> left);
        bool right = isIdentical(r1 -> right, r2 -> right);
        
        bool value = r1 -> data == r2 -> data;
        
        if(left && right && value){
            return true;
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
    int tc;
    cin>>tc;
    while(tc--){
        string str, str1;
        getline(cin, str);
        Node* rootA = buildTree(str);
        getline(cin, str1);
        Node* rootB = buildTree(str1);
        Solution obj;
        if(obj.isIdentical(rootA, rootB))
        {
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
}