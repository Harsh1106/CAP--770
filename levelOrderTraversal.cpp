#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct tree{
    int val;
    tree * left, *right;
    tree() : val(0), left(nullptr), right(nullptr){}
    tree(int x) : val(x), left(nullptr), right(nullptr){}
    tree(int x, tree *left, tree *right) : val(x), left(left), right(right){}
};

class sol{
    public:
        vector<vector<int>> levelOrder(tree *root){
            vector<vector<int>> ans;
            if(root == NULL) return ans;
            queue<tree*> q;
            while(!q.empty()){
                int size = q.size();
                vector<int> level;
                for(int i = 0 ; i < size ; i++){
                    tree *node = q.front();
                    q.pop();
                    if(node -> left != NULL){
                        q.push(node -> left);
                    }
                    if(node -> right != NULL){
                        q.push(node -> right);
                    }
                    level.push_back(node -> val);
                }
                ans.push_back(level);
            }
            return ans;
        }
        void print(vector<vector<int>> levels){
            for(const vector<int>& level :  levels){
                for(int value : level){
                    cout<<value<<" ";
                }
                cout<<endl;
            }
        }
};

int main(){
    struct tree* root = new tree(1);
    root -> left = new tree(2);
    root -> left -> left = new tree(4);
    root -> left -> right = new tree(5);
    root -> left -> right -> left = new tree(6);
    root -> right = new tree(3);
    root -> right -> left = new tree(7);
    root -> right -> right = new tree(8);

    sol obj;
    vector<vector<int>> levels = obj.levelOrder(root); 
    obj.print(levels);
    cout<<"hi";
    
    return 0;
}