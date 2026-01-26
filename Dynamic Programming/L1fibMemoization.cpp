#include <bits/stdc++.h>
using namespace std;

// T.C - O(n)
// S.C - O(n)   // dp array + recursion stack

int solveUsingMem(int n, vector<int> &dp){
    // base case
    if(n == 0 || n == 1){
        return n;
    }

    // if already computed
    if(dp[n] != -1){
        return dp[n];
    }

    // compute and store
    dp[n] = solveUsingMem(n - 1, dp) + solveUsingMem(n - 2, dp);
    return dp[n];
}

int main() {

    /*
    Sample Input:
    5

    Sample Output:
    5

    Explanation:
    Fibonacci sequence:
    0 1 1 2 3 5
    */

    int n;
    cin >> n;

    vector<int> dp(n + 1, -1);
    cout << solveUsingMem(n, dp) << endl;

    return 0;
}
