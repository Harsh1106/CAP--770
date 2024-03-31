// Diameter of tree: Longest path of any 2 nodes basically it is number of nodes.
// Longest path b/w any two nodes like leaf and root.
// TC: O(N)
// SC: O(Height of tree)

#include <iostream>
#include <string>
#include<sstream>
#include<queue>
#include <utility> // for pair

using namespace std;

// Structure for the Node of the Binary Tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

// Class Solution to find the diameter of a binary tree
class Solution {
private:
    int height(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        int left = height(node->left);
        int right = height(node->right);
        int ans = max(left, right) + 1;
        return ans;
    }

public:
    // Function to return the diameter of a Binary Tree.
    pair<int, int> diameterFast(Node* root) {
        if (root == nullptr) {
            return make_pair(0, 0);
        }
        pair<int, int> left = diameterFast(root->left);
        pair<int, int> right = diameterFast(root->right);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;

        pair<int, int> ans;
        ans.first = max(op1, max(op2, op3));
        ans.second = max(left.second, right.second) + 1;

        return ans;
    }

    int diameter(Node* root) {
        return diameterFast(root).first;
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
        cout << obj.diameter(root) << endl;
    }
    return 0;
}
