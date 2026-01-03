// Cycle detection

/*
Undirected graph - BFS and DFS
Directed graph - BFS and DFS

BFS and DFS are traversal methods
BFS - Level order traversal(just like tree..but here we use neighbour
term instead of child)
DFS - Recursion
*/

// GFG - Undirected Graph Cycle

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;


// T.C - O(V + E) , S.C - O(V + E)

class Graph
{
public:
    unordered_map<int, vector<int>> adjList;

    // direction = 0 → undirected
    // direction = 1 → directed
    void addEdge(int u, int v, bool direction)
    {
        if (direction == 1)
        {
            adjList[u].push_back(v);
        }
        else
        {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }
};

class Solution
{
public:
    bool checkCycleUsingBFS(
        int src,
        unordered_map<int, vector<int>> &adjList,
        unordered_map<int, bool> &visited,
        unordered_map<int, int> &parent)
    {
        queue<int> q;

        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while (!q.empty())
        {
            int currNode = q.front();
            q.pop();

            for (auto nbr : adjList[currNode])
            {
                if (!visited[nbr])
                {
                    visited[nbr] = true;
                    parent[nbr] = currNode;
                    q.push(nbr);
                }
                else if (nbr != parent[currNode])
                {
                    return true; // cycle found
                }
            }
        }
        return false;
    }

    bool isCycle(int V, unordered_map<int, vector<int>> &adjList)
    {
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;

        // handle disconnected components
        for (int src = 0; src < V; src++)
        {
            if (!visited[src])
            {
                if (checkCycleUsingBFS(src, adjList, visited, parent))
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

    // Undirected graph (direction = 0)
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(2, 3, 0);
    g.addEdge(3, 0, 0); // creates a cycle

    int V = 4;

    Solution obj;
    bool hasCycle = obj.isCycle(V, g.adjList);

    if (hasCycle)
        cout << "Cycle detected\n";
    else
        cout << "No cycle detected\n";

    return 0;
}
