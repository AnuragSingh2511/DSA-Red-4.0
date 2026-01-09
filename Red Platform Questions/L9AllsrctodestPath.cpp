#include <bits/stdc++.h>
using namespace std;

// T.C - O(2^n * n)
// S.C - O(n)

class Solution {
public:

    void dfs(int src, int dest,
             vector<int> &temp,
             vector<vector<int>> &paths,
             vector<vector<int>> &graph)
    {
        // store current node
        temp.push_back(src);

        if (src == dest) {
            paths.push_back(temp);
            return;
        }

        // explore neighbors
        for (auto nbr : graph[src]) {
            dfs(nbr, dest, temp, paths, graph);
            // backtracking
            temp.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> tempPath;
        vector<vector<int>> paths;

        int src = 0;
        int dest = graph.size() - 1;

        dfs(src, dest, tempPath, paths, graph);
        return paths;
    }
};

int main() {

    Solution s;   // object creation to access non-static member functions

    int n;
    cin >> n;

    /*
    4
    2 1 2
    1 3
    1 3
    0

    o/p: 

    0 1 3
    0 2 3

    */

    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++) {
        int sz;
        cin >> sz;
        graph[i].resize(sz);
        for (int j = 0; j < sz; j++) {
            cin >> graph[i][j];
        }
    }

    vector<vector<int>> result = s.allPathsSourceTarget(graph);

    for (auto &path : result) {
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
