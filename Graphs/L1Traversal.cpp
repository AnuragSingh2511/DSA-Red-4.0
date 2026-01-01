#include <iostream>
#include <queue>
#include <unordered_map>
#include <map>
#include <vector>
using namespace std;

class Graph
{
public:
    // adjacency list
    unordered_map<int, vector<int>> adjList;
    //   map<int , vector<int> > adjList;

    // direction = 1 -> directed edge
    // direction = 0 -- undirected edge
    void addEdge(int u, int v, bool direction)
    {
        if (direction == 1)
        {
            // directed edge -> u->v
            adjList[u].push_back(v);
        }
        else
        {
            // undirected edge
            // u--v equivalent to  u->v , v->u
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    void printAdjacencyList()
    {
        for (auto i : adjList)
        {
            // i -> record or pair of key and value
            // i.first -> int
            // i.second -> vector<int>
            cout << i.first << ": ";
            cout << "{";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << "}" << endl;
        }
    }

    void bfsTraversal(int n)
    {
        queue<int> q;
        unordered_map<int, bool> visited;

        // SUPER IMPORTANT LOOP (same idea as DFS)
        for (int src = 0; src < n; src++)
        {
            if (!visited[src])
            {
                q.push(src);
                visited[src] = true;

                while (!q.empty())
                {
                    int frontNode = q.front();
                    q.pop();
                    cout << frontNode << ", ";

                    for (auto nbr : adjList[frontNode])
                    {
                        if (!visited[nbr])
                        {
                            q.push(nbr);
                            visited[nbr] = true;
                        }
                    }
                }
            }
        }
    }

    // entire DFS logic resides inside the dfsHelper function
    void dfshelper(int src, unordered_map<int, bool> &visited)
    {
        // jaise hi call aai , toh sbse pehle ans print kro
        // visited true mark karo
        cout << src << ", ";
        visited[src] = true;
        // ab current node se iske nbr ki taraf call marni hai
        for (auto nbr : adjList[src])
        {
            // agar nbr visited nahi hai
            // toh uske liye DFS call karna hai
            if (!visited[nbr])
            {
                dfshelper(nbr, visited);
            }
        }
    }
    void dfsTraversal(int src, int n)
    {
        unordered_map<int, bool> visited;
        // fn call for src node
        // SUPER IMP LOOP..handles disconnected components
        for (int src = 0; src < n; src++)
        {
            if (!visited[src])
            {
                dfshelper(src, visited);
            }
        }
    }
};

int main()
{
    Graph g;

    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 8, 1);
    g.addEdge(3, 4, 1);
    g.addEdge(8, 4, 1);
    g.addEdge(4, 5, 1);
    g.addEdge(4, 7, 1);
    g.addEdge(5, 6, 1);
    g.addEdge(7, 6, 1);

    g.printAdjacencyList();
    g.bfsTraversal(9); // 9 is no. of nodes ..no use of src in bfs
    // cout << "DFS: ";
    // g.dfsTraversal(0, 9);

    return 0;
}