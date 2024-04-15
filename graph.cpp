#include <iostream>

#define V 5 // Number of vertices in the graph

using namespace std; // Include standard namespace

// Function to initialize the matrix to zero
void init(int arr[][V]) {
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      arr[i][j] = 0;
    }
  }
}

// Function to add edges to the graph
void insertEdge(int arr[][V], int i, int j) {
  arr[i][j] = 1;
  arr[j][i] = 1; // Add for undirected graph
}

// Function to print the matrix elements
void printAdjMatrix(int arr[][V]) {
  for (int i = 0; i < V; i++) {
    cout << i << ": ";
    for (int j = 0; j < V; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  int adjMatrix[V][V];

  init(adjMatrix);
  insertEdge(adjMatrix, 0, 1);
  insertEdge(adjMatrix, 0, 2);
  insertEdge(adjMatrix, 1, 2);
  insertEdge(adjMatrix, 2, 0); // Duplicate insertion for undirected graph commented out
  insertEdge(adjMatrix, 2, 3);
  insertEdge(adjMatrix, 4, 3);

  printAdjMatrix(adjMatrix);

  return 0;
}
