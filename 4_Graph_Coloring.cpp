#include <iostream>
#include <vector>

using namespace std;

// Function to check if a vertex can be assigned a color
bool isSafe(const vector<vector<int>>& graph, const vector<int>& colors, int vertex, int color) {
    for (int neighbor : graph[vertex]) {
        if (colors[neighbor] == color) {
            return false; // If neighbor already has the same color, not safe
        }
    }
    return true;
}

// Function to solve graph coloring problem using backtracking
bool graphColoringBacktracking(const vector<vector<int>>& graph, vector<int>& colors, int vertex, int num_colors) {
    int num_vertices = graph.size();
    if (vertex == num_vertices) {
        return true; // All vertices are colored
    }

    for (int color = 1; color <= num_colors; ++color) {
        if (isSafe(graph, colors, vertex, color)) {
            colors[vertex] = color; // Assign color to vertex

            // Recur to color rest of the vertices
            if (graphColoringBacktracking(graph, colors, vertex + 1, num_colors)) {
                return true;
            }

            // If coloring with current color doesn't lead to a solution,
            // backtrack and try the next color
            colors[vertex] = 0; // Undo the color assignment (backtrack)
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

    // Solve using Backtracking
    cout << "Solution using Backtracking:\n";
    if (graphColoringBacktracking(graph, colors, 0, num_vertices)) {
        for (int i = 0; i < num_vertices; ++i) {
            cout << "Vertex " << i << " is colored with color " << colors[i] << endl;
        }
    } else {
        cout << "No solution exists!\n";
    }

    return 0;
}
