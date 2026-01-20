#include <bits/stdc++.h>
using namespace std;

// T.C - O(2^n)
// S.C - O(n)   // recursion stack

class Solution {
public:
    bool solve(vector<int>& nums, int target, int i){
        if(target == 0) return true;
        if(target < 0 || i == nums.size()) return false;

        bool inc = solve(nums, target - nums[i], i + 1);
        bool exc = solve(nums, target, i + 1);

        return inc || exc;
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0) return false;

        int target = sum >> 1;   // sum / 2
        return solve(nums, target, 0);
    }
};

int main() {

    /*
    Sample Input:
    4
    1 5 11 5

    Sample Output:
    true
    */

    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    Solution s;
    cout << "Output: " << boolalpha << s.canPartition(nums) << endl;

    return 0;
}
