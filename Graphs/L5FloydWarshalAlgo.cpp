#include <iostream>
#include <unordered_map>
#include <set>
#include <list>
#include <vector>
#include <limits.h>
using namespace std;

// T.C - O(n³)
// S.C - O(n²) + O(V + E) , But since: n² dominates V + E for dense graphs
//S.C - O(n²)


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

    void floydWarshalAlgo(int n){
        //  vector<vector<int> > dist(n, vector<int>(n, INT_MAX)); //INT_MAX causes int min values in o/p so prefer large no 1e9
         vector<vector<int> > dist(n, vector<int>(n, 1e9)); //2D array

         //step 1 diagonal pe zero rakh diye
         for(int i=0; i<n; i++){
            dist[i][i] =0;
         }

         //step 2: copy all distance from graph to matrix
         
         for(auto a: adjList){
            for(auto b: a.second){
                int u = a.first;
                int v = b.first;
                int wt = b.second;
                dist[u][v] = wt;
            }
         }

         //main logic of helper node
         for(int helper = 0; helper < n; helper++){
            for(int u = 0; u < n; u++){
            for(int v = 0; v < n ; v++){
                dist[u][v] = min(dist[u][v] , dist[u][helper] + dist[helper][v]);
            }
            }
         }

         cout << "Printing Result of FW algo: " << endl;
         for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                cout << dist[i][j] << ", ";
            }
            cout << endl;
         }
    }
    
};

int main()
{
    Graph g;

    g.addEdge(0, 2, -2, 1);
    g.addEdge(1, 0, 4, 1);
    g.addEdge(1, 2, 3, 1);
    g.addEdge(3, 1, -1, 1);
    g.addEdge(2, 3, 2, 1);
   

    g.floydWarshalAlgo(4);

    return 0;
}