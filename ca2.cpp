// a logistics company needs to find the shortest delivery routes between all its distribution centers located across multiple cities. The distance or time taken between each pair of centers varies due to traffic, road conditions, or geographical obstacles. The company aims to optimize delivery times by knowing the shortest paths between any two centers.
// Problem Statement: Use the all pairs Shortest Path algo to determine the min delivery time between any two distribution centers in the network.
// C++ Program for Floyd Warshall Algorithm

#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>
using namespace std;

const int INF = numeric_limits<int>::max();

void floydWarshall(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<vector<int>> dist(V, vector<int>(V, INF));

    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (i == j) {
                dist[i][j] = 0;
            } else if (graph[i][j] != INF) {
                dist[i][j] = graph[i][j];
            }
        }
    }

    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    for (int i = 0; i < V; ++i) {
        if (dist[i][i] < 0) {
            cout << "Negative weight cycle detected" << std::endl;
            return;
        }
    }

    cout << "Shortest path matrix:" << std::endl;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INF) {
                cout << "INF" << std::setw(5);
            } else {
                cout << setw(5) << dist[i][j];
            }
        }
        cout << endl;
    }
}

int main() {
    vector<std::vector<int>> graph = {
        {0, 3, INF, INF},
        {INF, 0, 1, 7},
        {INF, INF, 0, 2},
        {2, INF, INF, 0}
    };

    floydWarshall(graph);

    return 0;
}
