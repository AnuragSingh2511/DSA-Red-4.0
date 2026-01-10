#include <bits/stdc++.h>
using namespace std;

// T.C - O(V^2)
// S.C - O(V + E)

class Solution {
public:
    int spanningTree(int V, vector<vector<int>> &edges) {

        // Convert edges list to adjacency list
        vector<vector<pair<int,int>>> adj(V);
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<int> key(V, INT_MAX);
        vector<bool> mst(V, false);

        key[0] = 0;
        int mstSum = 0;

        for(int i = 0; i < V; i++){
            int u = -1;
            int mini = INT_MAX;

            // pick min key node
            for(int v = 0; v < V; v++){
                if(!mst[v] && key[v] < mini){
                    mini = key[v];
                    u = v;
                }
            }

            mst[u] = true;
            mstSum += key[u];

            // relax neighbours
            for(auto &nbr : adj[u]){
                int v = nbr.first;
                int wt = nbr.second;
                if(!mst[v] && wt < key[v]){
                    key[v] = wt;
                }
            }
        }

        return mstSum;
    }
};

int main() {

    /*
    Sample Input:
    3 3
    0 1 5
    1 2 3
    0 2 1

    Output:
    4
    */

    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(3));
    for(int i = 0; i < E; i++){
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    Solution s;
    cout << s.spanningTree(V, edges);

    return 0;
}
