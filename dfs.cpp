// DFS: Depth First Search

#include<iostream>
#include <map>
#include <list>

using namespace std;

class DFS{
    public:
        map<int, bool>  visited;
        map<int, list<int> > adj;
        void addEdge(int v, int w);

        void dfs(int v);
};

void DFS :: addEdge(int v, int w){
    adj[v].push_back(w);
}

void DFS :: dfs(int v){
    visited[v] = true;
    cout<<v<<" ";
    list<int> :: iterator i;
    for(i = adj[v].begin() ; i != adj[v].end() ; i++){
        if(!visited[*i]){
            dfs(*i);
        }
    }
}

int main(){
    DFS d;
    d.addEdge(0,1);
    d.addEdge(0, 2);
    d.addEdge(1, 2);
    d.addEdge(2, 0);
    d.addEdge(2, 3);
    d.addEdge(3, 3);
    cout<<"After the DFS: ";
    d.dfs(2);
    return 0;
}