#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


// T.C - O(V + E) , S.C - O(V + E)

class Graph {
public:
    unordered_map<int, vector<int>> adjList;

    // direction = 0 → undirected
    // direction = 1 → directed
    void addEdge(int u, int v, bool direction) {
        if (direction == 1) {
            adjList[u].push_back(v);
        } else {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }
};

class Solution {
public:
    bool dfsHelper(
        int src,
        unordered_map<int, vector<int>> &adjList,
        int parent,
        unordered_map<int, bool> &visited
    ) {
        visited[src] = true;

        for (auto nbr : adjList[src]) {
            if (!visited[nbr]) {
                if (dfsHelper(nbr, adjList, src, visited)) {
                    return true;
                }
            }
            // visited and not parent → cycle
            else if (nbr != parent) {
                return true;
            }
        }
        return false;
    }

    bool checkCycleUsingDFS(unordered_map<int, vector<int>> &adjList, int V) {
        unordered_map<int, bool> visited;

        // handle disconnected components
        for (int src = 0; src < V; src++) {
            if (!visited[src]) {
                if (dfsHelper(src, adjList, -1, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Graph g;

    // Undirected graph
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(2, 3, 0);
    g.addEdge(3, 0, 0); // creates cycle

    int V = 4;

    Solution obj;
    bool hasCycle = obj.checkCycleUsingDFS(g.adjList, V);

    if (hasCycle)
        cout << "Cycle detected\n";
    else
        cout << "No cycle detected\n";

    return 0;
}
