#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <utility>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

// Function to add an edge to the adjacency list
void addEdge(vector<vector<pii>>& adjList, int u, int v, int weight) {
    adjList[u].push_back({v, weight});
    adjList[v].push_back({u, weight}); // For undirected graph
}

// Prim's algorithm function
int prim(vector<vector<pii>>& adjList, int V) {
    vector<bool> vis(V, false);
    int ans = 0;
    set<pii> st;

    st.insert({0, 0});
    while (!st.empty()) {
        auto fr = *st.begin();
        st.erase(st.begin());
        int dist = fr.first;
        int node = fr.second;

        if (vis[node]) continue;

        vis[node] = true;
        ans += dist;

        for (auto neighbor : adjList[node]) {
            int neighborNode = neighbor.first;
            int neighborDist = neighbor.second;
            if (!vis[neighborNode]) {
                st.insert({neighborDist, neighborNode});
            }
        }
    }
    return ans;
}

int main() {
    int V = 5; // Number of vertices
    vector<vector<pii>> adjList(V);

    // Adding edges
    addEdge(adjList, 0, 1, 2);
    addEdge(adjList, 0, 3, 6);
    addEdge(adjList, 1, 2, 3);
    addEdge(adjList, 1, 3, 8);
    addEdge(adjList, 1, 4, 5);
    addEdge(adjList, 2, 4, 7);
    addEdge(adjList, 3, 4, 9);

    int minCost = prim(adjList, V);
    cout << "Minimum Cost Spanning Tree: " << minCost << endl;

    return 0;
}
