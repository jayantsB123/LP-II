#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

class Graph {
    int V;
    vector<Edge> edges;

public:
    Graph(int V) : V(V) {}

    void addEdge(int src, int dest, int weight) {
        Edge edge = {src, dest, weight};
        edges.push_back(edge);
    }

    // DFS function to detect cycle
    bool isCyclic(int v, vector<bool>& visited, vector<bool>& inStack) {
        if (!visited[v]) {
            visited[v] = true;
            inStack[v] = true;

            for (const auto& edge : edges) {
                if (edge.src == v) {
                    if (!visited[edge.dest] && isCyclic(edge.dest, visited, inStack))
                        return true;
                    else if (inStack[edge.dest])
                        return true;
                }
            }
        }
        inStack[v] = false;
        return false;
    }

    void DFS(int v, vector<bool>& visited) {
        visited[v] = true;

        for (const auto& edge : edges) {
            if (edge.src == v && !visited[edge.dest]) {
                DFS(edge.dest, visited);
            }
        }
    }

    // Kruskal's algorithm with cycle detection using DFS
    void kruskalMST() {
        // Sort edges by weight
        sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
            return a.weight < b.weight;
        });

        vector<bool> inStack(V, false);
        vector<bool> visited(V, false);

        for (const auto& edge : edges) {
            // Check if adding this edge creates a cycle
            if (!isCyclic(edge.src, visited, inStack)) {
                cout << edge.src << " -- " << edge.dest << " : " << edge.weight << endl;
                DFS(edge.src, visited);
            }
        }
    }
};

int main() {
    int V = 4; // Number of vertices
    Graph graph(V);

    // Add edges
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 6);
    graph.addEdge(0, 3, 5);
    graph.addEdge(1, 3, 15);
    graph.addEdge(2, 3, 4);

    cout << "Edges in MST: " << endl;
    graph.kruskalMST();

    return 0;
}
