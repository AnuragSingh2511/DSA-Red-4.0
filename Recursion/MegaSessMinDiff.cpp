#include <bits/stdc++.h>
using namespace std;

// T.C - O(C^R)
// S.C - O(R)
//
// R = number of rows
// C = max number of columns in a row
// Exponential due to picking one element from each row

class Solution {
public:
    int solve(vector<vector<int>>& mat, int target, int sum, int row){
        if(row == mat.size())
            return abs(target - sum);

        int ans = INT_MAX;
        for(int col = 0; col < mat[row].size(); col++){
            int recAns = solve(mat, target, sum + mat[row][col], row + 1);
            ans = min(ans, recAns);
        }
        return ans;
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int sum = 0;
        int row = 0;
        return solve(mat, target, sum, row);
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

    Explanation:
    1 + 5 + 7 = 13 → |13 - 13| = 0
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
