#include <bits/stdc++.h>
using namespace std;

// T.C - O(E log E)
// S.C - O(V)

class Solution {
public:
    static bool mycmp(vector<int> &a, vector<int> &b){
        return a[2] < b[2];
    }

    int findParent(vector<int> &parent, int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findParent(parent, parent[node]);
    }

    void unionSet(int u, int v, vector<int> &parent, vector<int> &rank){
        u = findParent(parent, u);
        v = findParent(parent, v);

        if(u == v) return;

        if(rank[u] < rank[v]){
            parent[u] = v;
        }
        else if(rank[v] < rank[u]){
            parent[v] = u;
        }
        else{
            parent[v] = u;
            rank[u]++;
        }
    }

    int spanningTree(int V, vector<vector<int>>& edges) {

        // DSU init
        vector<int> parent(V);
        vector<int> rank(V, 0);

        for(int i = 0; i < V; i++){
            parent[i] = i;
        }

        // sort edges by weight
        sort(edges.begin(), edges.end(), mycmp);

        int ans = 0;

        // Kruskal
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if(findParent(parent, u) != findParent(parent, v)){
                unionSet(u, v, parent, rank);
                ans += w;
            }
        }

        return ans;
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
