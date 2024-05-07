#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

bool isSafe(const vector<vector<int>>& graph, const vector<int>& colors, int vertex, int color) {
    for (int neighbor : graph[vertex]) {
        if (colors[neighbor] == color) {
            return false; // If neighbor already has the same color, not safe
        }
    }
    return true;
}

int getDegree(const vector<vector<int>>& graph, int vertex) {
    return graph[vertex].size();
}

bool graphColoringBranchAndBound(const vector<vector<int>>& graph, vector<int>& colors, int vertex, int num_colors) {
    int num_vertices = graph.size();
    if (vertex == num_vertices) {
        return true; // All vertices are colored
    }

    // Sort vertices based on degree (descending order)
    vector<pair<int, int>> vertices_with_degree;
    for (int i = 0; i < num_vertices; ++i) {
        vertices_with_degree.push_back({getDegree(graph, i), i});
    }
    sort(vertices_with_degree.rbegin(), vertices_with_degree.rend());

    for (const auto& vertex_pair : vertices_with_degree) {
        int current_vertex = vertex_pair.second;
        if (colors[current_vertex] == 0) { // Vertex not colored yet
            for (int color = 1; color <= num_colors; ++color) {
                if (isSafe(graph, colors, current_vertex, color)) {
                    colors[current_vertex] = color; // Assign color to vertex
                    if (graphColoringBranchAndBound(graph, colors, vertex + 1, num_colors)) {
                        return true;
                    }
                    colors[current_vertex] = 0; // Backtrack
                }
            }
        }
    }

    return false;
}

int main() {
    // Default input
    int num_vertices = 6;
    int num_edges = 7;
    vector<vector<int>> graph = {{1, 2}, {0, 2, 3}, {0, 1, 3, 4}, {1, 2, 4, 5}, {2, 3, 5}, {3, 4}};
    vector<int> colors(num_vertices, 0);
    int num_colors = 3;

    // Solve using Branch and Bound
    cout << "Solution using Branch and Bound:\n";
    if (graphColoringBranchAndBound(graph, colors, 0, num_colors)) {
        for (int i = 0; i < num_vertices; ++i) {
            cout << "Vertex " << i << " is colored with color " << colors[i] << endl;
        }
    } else {
        cout << "No solution exists!\n";
    }

    return 0;
}
