//
// Created by laura on 6/11/2024.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, const std::vector<std::vector<int>>& adjList, std::vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        // vecinos
        for (int neighbor : adjList[node]) { // toma el valor del node
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    int n = 5; // Número de nodos
    std::vector<std::vector<int>> adjList = {
            {1, 2},    // Nodo 0 conecta con 1 y 2
            {0, 3, 4}, // Nodo 1 conecta con 0, 3 y 4
            {0},       // Nodo 2 conecta con 0
            {1},       // Nodo 3 conecta con 1
            {1}        // Nodo 4 conecta con 1
    };

    std::vector<bool> visited(n, false);
    std::cout << "BFS desde el nodo 0: ";
    bfs(0, adjList, visited);
}