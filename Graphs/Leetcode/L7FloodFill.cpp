#include <iostream>
#include <vector>
#include <map>
using namespace std;

// T.C - O(n * m)
// S.C - O(n * m)

class Solution {
public:
    bool isSafe(int newX, int newY,
                map<pair<int,int>, bool> &vis,
                vector<vector<int>> &ans,
                int oldColor)
    {
        if (newX >= 0 && newY >= 0 &&
            newX < ans.size() &&
            newY < ans[0].size() &&
            ans[newX][newY] == oldColor &&
            vis[{newX, newY}] == false)
        {
            return true;
        }
        return false;
    }

    void dfs(int sr, int sc,
             int oldColor, int newColor,
             map<pair<int,int>, bool> &vis,
             vector<vector<int>> &ans)
    {
        vis[{sr, sc}] = true;
        ans[sr][sc] = newColor;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int newX = sr + dx[i];
            int newY = sc + dy[i];

            if (isSafe(newX, newY, vis, ans, oldColor))
            {
                dfs(newX, newY, oldColor, newColor, vis, ans);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color)
    {
        vector<vector<int>> ans = image;
        int oldColor = image[sr][sc];

        if (oldColor == color)
            return ans;

        map<pair<int,int>, bool> vis;
        dfs(sr, sc, oldColor, color, vis, ans);

        return ans;
    }
};

int main()
{
    vector<vector<int>> image = {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };

    int sr = 1, sc = 1, color = 2;

    Solution s;
    vector<vector<int>> result = s.floodFill(image, sr, sc, color);

    cout << "Flood Fill Result:\n";
    for (auto &row : result)
    {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
