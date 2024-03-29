#include<iostream>
using namespace std;

class TreeNode { // tree node is defined
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data)
    {
        val = data;
        left = nullptr;
        right = NULL;
    }
};

void inorder(TreeNode* root)
{
    //base case
    if (root == NULL)
        return;
    //traverse left sub tree
    inorder(root->left);
    //traverse current node secondly
    cout<<"%d "<<root->val;
    //traverse right sub tree finally
    inorder(root->right);
}
void postorder(TreeNode* root)
{
    //base case
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout<<"%d ", root->val;
}
void preorder(TreeNode* root)
{
    //base case
    if (root == NULL)
        return;

    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);

}
int main()
{
    //building the tree
    TreeNode* t = new TreeNode(7);
    t->left = new TreeNode(1);
    t->left->left = new TreeNode(0);
    t->left->right = new TreeNode(3);
    t->left->right->left = new TreeNode(2);
    t->left->right->right = new TreeNode(5);
    t->left->right->right->left = new TreeNode(4);
    t->left->right->right->right = new TreeNode(6);
    t->right = new TreeNode(9);
    t->right->left = new TreeNode(8);
    t->right->right = new TreeNode(10);

    cout<<"Inorder traversal of the above tree is:\n";
    inorder(t);
    cout<<"\nPostorder traversal of the above tree is:\n";
    postorder(t);
    cout<<"\nPretorder traversal of the above tree is:\n";
    preorder(t);
    return 0;
}




// Inorder / Preorder / Postorder
//  LNR        NLR       LRN
// L = Left, N = Node, R = Right