#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int V;
    unordered_map<int, vector<int>> adjList;
    vector<vector<int>> edges;

    // Constructor
    // T.C: O(1)
    // S.C: O(1)
    Graph(int vertices) {
        V = vertices;
    }

    // Add directed edge u -> v
    // T.C: O(1)
    // S.C: O(1)
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        edges.push_back({u, v});
    }

    // Kahn's Algorithm (BFS) for cycle detection
    // T.C: O(V + E)
    // S.C: O(V)
    void checkCycleUsingBFS(vector<int> &topoOrder) {

        unordered_map<int, int> indegree;
        queue<int> q;

        // Initialize indegree of all nodes as 0
        // T.C: O(V)
        // S.C: O(V)
        for (int i = 0; i < V; i++) {
            indegree[i] = 0;
        }

        // Calculate indegree
        // T.C: O(E)
        for (auto &i : edges) {
            int u = i[0];
            int v = i[1];
            indegree[v]++;
        }

        // Push all nodes with indegree 0
        // T.C: O(V)
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // BFS
        // T.C: O(V + E)
        while (!q.empty()) {
            int frontNode = q.front();
            q.pop();

            topoOrder.push_back(frontNode);

            for (auto nbr : adjList[frontNode]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
    }

    // Cycle detection function
    // T.C: O(V + E)
    // S.C: O(V + E)
    bool isCyclic() {

        vector<int> topoOrder;
        checkCycleUsingBFS(topoOrder);

        // If topo order size != V, cycle exists
        return topoOrder.size() != V;
    }
};


int main() {

    // Example 1: Graph WITH cycle
    Graph g1(4);
    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    g1.addEdge(3, 1);  // Cycle

    cout << "Graph 1 has cycle? ";
    cout << (g1.isCyclic() ? "YES" : "NO") << endl;

    // Example 2: Graph WITHOUT cycle
    Graph g2(6);
    g2.addEdge(5, 2);
    g2.addEdge(5, 0);
    g2.addEdge(4, 0);
    g2.addEdge(4, 1);
    g2.addEdge(2, 3);
    g2.addEdge(3, 1);

    cout << "Graph 2 has cycle? ";
    cout << (g2.isCyclic() ? "YES" : "NO") << endl;

    return 0;
}
