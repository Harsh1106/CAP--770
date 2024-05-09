// BFS: Breadth First Search
// It is just a traversal technique
// TC: O(V + E)
// SC: O(V)
#include<iostream>
#include<vector>
#include<queue>
using namespace std;


void BFS(vector<vector<int>> &adjList, int start, vector<bool> &visited){
    queue<int> q;

    visited[start] = true;
    q.push(start);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        cout<<curr<<" ";
        for(int neighbour : adjList[curr]){
            if(!visited[neighbour]){
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
}

void addEdge(vector<vector<int>> &adjList, int u, int v){
    adjList[u].push_back(v);
}
int main(){
    int vertices = 5;
    vector<vector<int>> adjList(vertices);
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 4);
    vector<bool> visited(vertices, false);
    cout<<"Breadth first search traversal starting from index 0: "<<endl;
    BFS(adjList, 0, visited);


    return 0;
}