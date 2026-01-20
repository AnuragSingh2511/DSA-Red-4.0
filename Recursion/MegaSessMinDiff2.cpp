#include <bits/stdc++.h>
using namespace std;

// T.C - O(C^R)
// S.C - O(R)
//
// R = rows, C = columns per row

class Solution {
public:
    void solve(vector<vector<int>>& mat, int target,
               int sum, int row, int &mini) {

        if(row == mat.size()) {
            mini = min(mini, abs(target - sum));
            return;
        }

        for(int col = 0; col < mat[row].size(); col++) {
            solve(mat, target, sum + mat[row][col], row + 1, mini);
        }
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int sum = 0, row = 0;
        int mini = INT_MAX;

        solve(mat, target, sum, row, mini);
        return mini;
    }
};

int main() {

    /*
    Sample Input:
    3 3
    1 2 3
    4 5 6
    7 8 9
    13

    Sample Output:
    0
    */

    int r, c;
    cin >> r >> c;

    vector<vector<int>> mat(r, vector<int>(c));
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> mat[i][j];
        }
    }

    int target;
    cin >> target;

    Solution s;
    cout << "Output: " << s.minimizeTheDifference(mat, target) << endl;

    return 0;
}
