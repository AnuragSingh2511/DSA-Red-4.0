#include <iostream>
#include <unordered_map>
#include <set>
#include <list>
#include <vector>
#include <limits.h>
using namespace std;

// Weighted graph
class Graph
{
public:
    // adjacency list
    unordered_map<int, vector<pair<int, int>>> adjList;

    // direction = 1 -> directed edge
    // direction = 0 -- undirected edge
    void addEdge(int u, int v, int wt, bool direction)
    {
        if (direction == 1)
        {
            // directed edge -> u->v
            //  u -> (v, wt)
            adjList[u].push_back(make_pair(v, wt));
        }
        else
        {
            // undirected edge
            // u--v equivalent to  u->(v,wt) , v->(u,wt)
            adjList[u].push_back(make_pair(v, wt));
            adjList[v].push_back(make_pair(u, wt));
        }
    }

    void printAdjacencyList()
    {
        for (auto i : adjList)
        {
            // i -> record or pair of key and value
            // i.first -> int
            // i.second -> vector<pair<int,int>>
            cout << i.first << ": ";
            cout << "{";
            for (auto j : i.second)
            {
                // j -> pair<int,int>
                // j.first represents "v"
                // j.second represents "wt"
                cout << "(" << j.first << "," << j.second << "), ";
            }
            cout << "}" << endl;
        }
    }

    void shortestDistanceDijkstra(int src, int n)
    {
        vector<int> dist(n + 1, INT_MAX);
        set<pair<int, int>> st;

        // initial state
        dist[src] = 0;
        st.insert({0, src});

        // main logic
        while (!st.empty())
        {
            auto topElement = *(st.begin());
            int topNodeDistance = topElement.first;
            int topNode = topElement.second;

            // popr this node
            st.erase(st.begin());

            // nbr pe jao
            for (auto nbr : adjList[topNode])
            {
                // nbr is a pair
                //  nbr = {a,b}
                //  a -> node
                //  b -> wt
                int nbrNode = nbr.first;
                int nbrDistance = nbr.second;
                if (dist[topNode] + nbrDistance < dist[nbrNode])
                {
                    // 2 kaam karna hai
                    // distance array ko update karna hai
                    // set ko update karna hai
                    auto result = st.find({dist[nbrNode], nbrNode});
                    if (result != st.end())
                    {
                        // entry found
                        // remove this entry
                        st.erase(result);
                    }
                    dist[nbrNode] = dist[topNode] + nbrDistance;
                    st.insert({dist[nbrNode], nbrNode});
                }
            }
        }
        cout << "Printing the result" << endl;

        for (int i = 0; i < n; i++)
        {
            cout << dist[i] << " ";
        }
    }
};

int main()
{
    Graph g;

    g.addEdge(0, 5, 9, 1);
    g.addEdge(0, 3, 6, 1);
    g.addEdge(5, 4, 2, 1);
    g.addEdge(4, 3, 11, 1);
    g.addEdge(5, 1, 14, 1);
    g.addEdge(4, 1, 9, 1);
    g.addEdge(4, 2, 10, 1);
    g.addEdge(3, 2, 15, 1);
    g.addEdge(2, 1, 7, 1);

    g.shortestDistanceDijkstra(0, 6);

    return 0;
}