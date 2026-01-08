#include <bits/stdc++.h>
using namespace std;

// T.C - O(n * m)
// S.C - O(n * m)

class Solution
{
public:
    // oceanVisited -> true means water can reach that ocean
    void dfs(int row, int col,
             vector<vector<bool>> &oceanVisited,
             vector<vector<int>> &heights)
    {
        int totalRows = heights.size();
        int totalCols = heights[0].size();

        oceanVisited[row][col] = true;

        int dx[] = {0, 0, -1, 1}; // west, east, north, south
        int dy[] = {-1, 1, 0, 0};

        for (int i = 0; i < 4; i++)
        {
            int newX = row + dx[i];
            int newY = col + dy[i];

            if (newX >= 0 && newX < totalRows &&
                newY >= 0 && newY < totalCols &&
                oceanVisited[newX][newY] == false &&
                heights[row][col] <= heights[newX][newY])
            {
                dfs(newX, newY, oceanVisited, heights);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {

        int totalRows = heights.size();
        int totalCols = heights[0].size();

        vector<vector<bool>> pacificVisited(totalRows, vector<bool>(totalCols, false));
        vector<vector<bool>> atlanticVisited(totalRows, vector<bool>(totalCols, false));

        // first and last row
        for (int col = 0; col < totalCols; col++)
        {
            dfs(0, col, pacificVisited, heights);
            dfs(totalRows - 1, col, atlanticVisited, heights);
        }

        // first and last column
        for (int row = 0; row < totalRows; row++)
        {
            dfs(row, 0, pacificVisited, heights);
            dfs(row, totalCols - 1, atlanticVisited, heights);
        }

        vector<vector<int>> ans;
        for (int i = 0; i < totalRows; i++)
        {
            for (int j = 0; j < totalCols; j++)
            {
                if (pacificVisited[i][j] && atlanticVisited[i][j])
                {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};

int main()
{

    Solution s; // object creation for non-static member access

    int n, m;
    cin >> n >> m;
    /*
    5 5
1 2 2 3 5
3 2 3 4 4
2 4 5 3 1
6 7 1 4 5
5 1 1 2 4  

o/p:
0 4
1 3
1 4
2 2
3 0
3 1
4 0

    */

    vector<vector<int>> heights(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> heights[i][j];
        }
    }

    vector<vector<int>> result = s.pacificAtlantic(heights);

    for (auto &cell : result)
    {
        cout << cell[0] << " " << cell[1] << endl;
    }

    return 0;
}
