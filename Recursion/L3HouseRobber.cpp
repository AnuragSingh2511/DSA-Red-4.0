#include <bits/stdc++.h>
using namespace std;

// T.C - O(2^n)
// S.C - O(n)   // recursion stack

// Leetcode problem - 198

class Solution {
public:
    int solve(vector<int> &nums, int index){
        // base case
        if(index >= nums.size()){
            return 0;
        }

        // include current house
        int includeAns = nums[index] + solve(nums, index + 2);

        // exclude current house
        int excludeAns = solve(nums, index + 1);

        return max(includeAns, excludeAns);
    }

    int rob(vector<int>& nums) {
        int index = 0;
        return solve(nums, index);
    }
};

int main() {

    /*
    Sample Input:
    4
    1 2 3 1

    Sample Output:
    4

    Explanation:
    Rob house 0 and 2 -> 1 + 3 = 4
    */

    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    Solution s;
    cout << "Output: " << s.rob(nums) << endl;

    return 0;
}
