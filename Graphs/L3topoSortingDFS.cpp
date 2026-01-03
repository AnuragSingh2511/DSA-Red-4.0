#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int V;
    unordered_map<int, vector<int>> adjList;

    // Constructor
    // T.C: O(1)
    // S.C: O(1)
    Graph(int vertices) {
        V = vertices;
    }

    // Add edge u -> v
    // T.C: O(1)
    // S.C: O(1)
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    // DFS helper for Topological Sort
    // T.C: O(V + E)
    // S.C: O(V) (recursion stack + visited)
    void dfs(int src,
             unordered_map<int, bool> &visited,
             vector<int> &ans) {

        visited[src] = true;

        for (auto nbr : adjList[src]) {
            if (!visited[nbr]) {
                dfs(nbr, visited, ans);
            }
        }

        // Backtracking
        ans.push_back(src);
    }

    // Topological Sort
    // T.C: O(V + E)
    // S.C: O(V + E)
    vector<int> topoSort() {

        unordered_map<int, bool> visited;
        vector<int> ans;

        // Call DFS for all vertices
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, visited, ans);
            }
        }

        // Reverse for correct topo order
        reverse(ans.begin(), ans.end());

        return ans;
    }
};


int main() {

    // Create graph with 6 vertices
    Graph g(6);

    // Adding edges using addEdge
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    // Perform topological sort
    vector<int> topo = g.topoSort();

    cout << "Topological Sort: ";
    for (int node : topo) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
