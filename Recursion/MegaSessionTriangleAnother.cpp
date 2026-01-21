#include <bits/stdc++.h>
using namespace std;

// T.C - O(2^n)
// S.C - O(n)   // recursion stack
// n = number of rows in triangle

class Solution {
public:
    void solve(vector<vector<int>>& triangle,
               int row, int col,
               int sum, int &ans) {

        // base case: processed all rows
        if(row == triangle.size()) {
            ans = min(ans, sum);
            return;
        }

        // move down
        solve(triangle, row + 1, col,
              sum + triangle[row][col], ans);

        // move diagonal
        solve(triangle, row + 1, col + 1,
              sum + triangle[row][col], ans);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int ans = INT_MAX;
        solve(triangle, 0, 0, 0, ans);
        return ans;
    }
};

int main() {

    /*
    Sample Input:
    4
    2
    3 4
    6 5 7
    4 1 8 3

    Sample Output:
    11

    Explanation:
    2 -> 3 -> 5 -> 1 = 11
    */

    int n;
    cin >> n;

    vector<vector<int>> triangle(n);
    for(int i = 0; i < n; i++){
        triangle[i].resize(i + 1);
        for(int j = 0; j <= i; j++){
            cin >> triangle[i][j];
        }
    }

    Solution s;
    cout << "Output: " << s.minimumTotal(triangle) << endl;

    return 0;
}
