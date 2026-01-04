#include <iostream>
#include <unordered_map>
#include <set>
#include <list>
#include <vector>
#include <limits.h>
using namespace std;

// T.C - O(V * E)
// S.C - O(V + E)

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
    //bellman works for directed graph
    void bellmnanFordAlgo(int src, int n)
    {
        vector<int> dist(n, INT_MAX);
        // initial state
        dist[src] = 0;

        // n-1 times loop
        for (int i = 0; i < n - 1; i++)
        {
            // har edge pe jao and relaxation step karo
            for (auto a : adjList)
            {
                for (auto b : a.second)
                {
                    // a -> pair< int, list<pair<int,int> > >
                    // a.first -> u
                    // a.second -> nbr of u node -> list<pair<int,int> >
                    // b -> pair<int,int>
                    // b.first -> v;
                    // b.second -> weight
                    int u = a.first;
                    int v = b.first;
                    int wt = b.second;
                    if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
                    {
                        dist[v] = dist[u] + wt;
                    }
                }
            }
        }
        bool negativeCyclePresent = false;
        
        for (auto a : adjList)
            {
                for (auto b : a.second)
                {
                    // a -> pair< int, list<pair<int,int> > >
                    // a.first -> u
                    // a.second -> nbr of u node -> list<pair<int,int> >
                    // b -> pair<int,int>
                    // b.first -> v;
                    // b.second -> weight
                    int u = a.first;
                    int v = b.first;
                    int wt = b.second;
                    if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
                    {
                        dist[v] = dist[u] + wt;
                        negativeCyclePresent = true;
                        break;
                    }
                }
            }

            if(negativeCyclePresent == true){
                cout << " -ve cycle present " << endl;
            }
            else{
                cout << "-ve cycle not present" << endl;
            }

        cout << "Printing bellman for result:" << endl;

        for (int i = 0; i < n; i++)
        {
            cout << dist[i] << " ";
        }
    }
};

int main()
{
    Graph g;

    g.addEdge(0, 1, -1, 1);
    g.addEdge(1, 4, 2, 1);
    g.addEdge(0, 2, 4, 1);
    g.addEdge(3, 2, 5, 1);
    g.addEdge(4, 3, -3, 1);
    g.addEdge(1, 2, 3, 1);
    g.addEdge(1, 3, 2, 1);
    g.addEdge(3, 1, 1, 1);

    g.bellmnanFordAlgo(0, 5);

    return 0;
}