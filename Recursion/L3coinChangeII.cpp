#include <bits/stdc++.h>
using namespace std;

// T.C - O(2^n)   (exponential due to include/exclude recursion)
// S.C - O(amount)  (recursion depth in worst case)

class Solution {
public:
    int solve(int amount, int index, vector<int>& coins){
        // base cases
        if(amount == 0){
            return 1;
        }
        if(index >= coins.size()){
            return 0;
        }

        // include current coin
        int includeKaAns = 0;
        if(coins[index] <= amount){
            includeKaAns = solve(amount - coins[index], index, coins);
        }

        // exclude current coin
        int excludeKaAns = solve(amount, index + 1, coins);

        return includeKaAns + excludeKaAns;
    }

    int change(int amount, vector<int>& coins){
        int index = 0;
        return solve(amount, index, coins);
    }
};

int main() {

    /*
    Sample Input:
    5
    3
    1 2 5

    Sample Output:
    4

    Explanation:
    Ways:
    1+1+1+1+1
    1+1+1+2
    1+2+2
    5
    */

    int amount;
    cin >> amount;

    int n;
    cin >> n;

    vector<int> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }

    Solution s;
    cout << "Output: " << s.change(amount, coins) << endl;

    return 0;
}
