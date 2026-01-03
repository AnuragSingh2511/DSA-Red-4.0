// Time Complexity: O(V + E)
// Space Complexity: O(V + E)

#include <bits/stdc++.h>
using namespace std;

//GFG - Topological Sort (solved using BFS)

class Graph {
public:
    int V;
    unordered_map<int, vector<int>> adjList;

    Graph(int vertices) {
        V = vertices;
    }

    // directed edge u -> v
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    vector<int> topoSort() {
        unordered_map<int, int> indegree;
        queue<int> q;
        vector<int> ans;

        // initialize indegree
        for (int i = 0; i < V; i++) {
            indegree[i] = 0;
        }

        // calculate indegree
        for (auto& node : adjList) {
            for (auto& nbr : node.second) {
                indegree[nbr]++;
            }
        }

        // push nodes with indegree 0
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Kahn's Algorithm
        while (!q.empty()) {
            int frontNode = q.front();
            q.pop();

            ans.push_back(frontNode);

            for (auto nbr : adjList[frontNode]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        return ans;
    }
};

int main() {
    Graph g(6);

    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    vector<int> topo = g.topoSort();

    for (int node : topo) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
