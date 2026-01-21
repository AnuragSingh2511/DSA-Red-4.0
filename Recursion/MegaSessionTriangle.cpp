#include <bits/stdc++.h>
using namespace std;

// T.C - O(2^n)
// S.C - O(n)   // recursion stack
// n = number of rows in triangle

class Solution {
public:
    int solve(vector<vector<int>>& triangle, int row, int col){
        // base case: last row
        if(row == triangle.size() - 1){
            return triangle[row][col];
        }

        int down = triangle[row][col] + solve(triangle, row + 1, col);
        int plus = triangle[row][col] + solve(triangle, row + 1, col + 1);

        return min(down, plus);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        return solve(triangle, 0, 0);
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
