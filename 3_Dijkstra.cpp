#include<bits/stdc++.h>
using namespace std;
#define v 9

void dijkstra(vector<pair<int, int>> adjList[], int start){
    vector<bool> vis(v, false);
    vector<int> dist(v, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    vis[start] = true;

    pq.push({0, start});

    while (!pq.empty()){
        auto node = pq.top();
        pq.pop();

        for (auto neighbor : adjList[node.second]){
            int adjNode = neighbor.first;
            int edgeWeight = neighbor.second;

            if (node.first + edgeWeight < dist[adjNode]){
                dist[adjNode] = node.first + edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    // Output the distances
    cout << "Shortest distances from source vertex " << start << ":\n";
    for (int i = 0; i < v; ++i) {
        cout << "Vertex " << i << ": ";
        if (dist[i] == INT_MAX) {
            cout << "No path exists\n";
        } else {
            cout << dist[i] << "\n";
        }
    }
}

int main(){
    vector<pair<int, int>> adjList[v];
    
    // Define adjacency list representation
    adjList[0].push_back({1, 4});
    adjList[0].push_back({7, 8});
    adjList[1].push_back({0, 4});
    adjList[1].push_back({2, 8});
    adjList[1].push_back({7, 11});
    adjList[2].push_back({1, 8});
    adjList[2].push_back({3, 7});
    adjList[2].push_back({5, 4});
    adjList[2].push_back({8, 2});
    adjList[3].push_back({2, 7});
    adjList[3].push_back({4, 9});
    adjList[3].push_back({5, 14});
    adjList[4].push_back({3, 9});
    adjList[4].push_back({5, 10});
    adjList[5].push_back({2, 4});
    adjList[5].push_back({3, 14});
    adjList[5].push_back({4, 10});
    adjList[5].push_back({6, 2});
    adjList[6].push_back({5, 2});
    adjList[6].push_back({7, 1});
    adjList[6].push_back({8, 6});
    adjList[7].push_back({0, 8});
    adjList[7].push_back({1, 11});
    adjList[7].push_back({6, 1});
    adjList[7].push_back({8, 7});
    adjList[8].push_back({2, 2});
    adjList[8].push_back({6, 6});
    adjList[8].push_back({7, 7});

    dijkstra(adjList, 0);
    
    return 0;
}
