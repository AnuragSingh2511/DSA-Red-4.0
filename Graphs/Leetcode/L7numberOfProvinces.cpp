#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// T.C - O(n^2)
// S.C - O(n)

class Solution {
public:
    void dfs(int src,
             unordered_map<int, bool> &vis,
             int n,
             vector<vector<int>> &isConnected)
    {
        vis[src] = true;

        // check all neighbors using adjacency matrix
        for (int nbr = 0; nbr < n; nbr++)
        {
            if (isConnected[src][nbr] == 1 && !vis[nbr])
            {
                dfs(nbr, vis, n, isConnected);
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        unordered_map<int, bool> vis;
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, n, isConnected);
                count++;
            }
        }
        return count;
    }
};

int main()
{
    // Example input (VS Code runnable)
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    Solution s;
    cout << "Number of Provinces: "
         << s.findCircleNum(isConnected) << endl;

    return 0;
}
