// Question: Given a binary tree find its height.
// TC: O(N)
// SC: O(height)
// worst space complexity in case of tree will be in Skew Tree where height is equal to n.  
#include <iostream>
#include <string>
#include <queue>
#include <sstream>
using namespace std;

// Structure for the Node of the Binary Tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) : data(x), left(NULL), right(NULL) {}
};

// Class Solution to find the height of a binary tree
class Solution {
public:
    // Function to find the height of a binary tree
    int height(Node* node) {
        if (node == NULL) // Base case
            return 0;
        // Recursive case
        int left = height(node->left);
        int right = height(node->right);
        int ans = max(left, right) + 1;
        return ans;
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

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after reading t
    while (t--) {
        string treeString;
        getline(cin, treeString);
        Node* root = buildTree(treeString);
        Solution obj;
        cout << obj.height(root) << endl;
    }
    return 0;
}
