#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

// T.C - O(n * m)
// S.C - O(n * m)

class Solution {
public:

    bool isSafe(int newX, int newY,
                vector<vector<char>>& grid,
                map<pair<int,int>, bool> &vis)
    {
        if (newX >= 0 && newY >= 0 &&
            newX < grid.size() &&
            newY < grid[0].size() &&
            grid[newX][newY] == '1' &&
            vis[{newX, newY}] == false)
        {
            return true;
        }
        return false;
    }

    void bfs(int srcX, int srcY,
             vector<vector<char>>& grid,
             map<pair<int,int>, bool> &vis)
    {
        queue<pair<int,int>> q;
        q.push({srcX, srcY});
        vis[{srcX, srcY}] = true;

        int dx[] = {-1, 0, 1, 0}; // up, right, down, left
        int dy[] = {0, 1, 0, -1};

        while (!q.empty())
        {
            auto frontNode = q.front();
            q.pop();

            int x = frontNode.first;
            int y = frontNode.second;

            for (int i = 0; i < 4; i++)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if (isSafe(newX, newY, grid, vis))
                {
                    q.push({newX, newY});
                    vis[{newX, newY}] = true;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid)
    {
        map<pair<int,int>, bool> vis;
        int count = 0;

        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[{i, j}] && grid[i][j] == '1')
                {
                    bfs(i, j, grid, vis);
                    count++;
                }
            }
        }
        return count;
    }
};

int main()
{
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    Solution s;
    cout << "Number of Islands: " << s.numIslands(grid) << endl;

    return 0;
}
