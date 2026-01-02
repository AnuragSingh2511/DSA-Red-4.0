#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Time Complexity: O(V + E)
// Space Complexity: O(V + E)

class Graph
{
public:
    unordered_map<int, vector<int>> adjList;

    // direction = 1 → directed graph
    void addEdge(int u, int v, bool direction)
    {
        adjList[u].push_back(v);
        if (direction == 0)
        {
            adjList[v].push_back(u);
        }
    }
};

class Solution
{
public:
    bool dfsHelper(
        int src,
        unordered_map<int, vector<int>> &adjList,
        unordered_map<int, bool> &visited,
        unordered_map<int, bool> &dfsTracker)
    {
        visited[src] = true;
        dfsTracker[src] = true;

        for (auto nbr : adjList[src])
        {
            if (!visited[nbr])
            {
                if (dfsHelper(nbr, adjList, visited, dfsTracker))
                {
                    return true;
                }
            }
            // visited + still in recursion stack → cycle
            else if (dfsTracker[nbr])
            {
                return true;
            }
        }

        // backtracking (VERY IMPORTANT)
        dfsTracker[src] = false;
        return false;
    }

    bool checkCycleUsingDFS(int V, unordered_map<int, vector<int>> &adjList)
    {
        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsTracker;

        // handle disconnected components
        for (int src = 0; src < V; src++)
        {
            if (!visited[src])
            {
                if (dfsHelper(src, adjList, visited, dfsTracker))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Graph g;

    // Directed graph
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 1, 1); // creates cycle

    int V = 4;

    Solution obj;
    bool hasCycle = obj.checkCycleUsingDFS(V, g.adjList);

    if (hasCycle)
        cout << "Cycle detected\n";
    else
        cout << "No cycle detected\n";

    return 0;
}
