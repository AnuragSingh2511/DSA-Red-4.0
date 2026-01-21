#include <bits/stdc++.h>
using namespace std;

// T.C - O(n^n)   (worst case: every index tries all jumps)
// S.C - O(n)     (recursion stack)

class Solution {
public:
    bool solve(vector<int>& nums, int i){
        if(i == nums.size() - 1) return true;
        if(i > nums.size() - 1) return false;
        if(nums[i] == 0) return false;

        bool recAns = false;
        for(int jump = 1; jump <= nums[i]; jump++){
            recAns = recAns || solve(nums, i + jump);
        }
        return recAns;
    }

    bool canJump(vector<int>& nums) {
        return solve(nums, 0);
    }
};

int main() {

    /*
    Sample Input:
    5
    2 3 1 1 4

    Sample Output:
    true

    Explanation:
    0 -> 1 -> 4 (reachable)
    */

    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    Solution s;
    cout << "Output: " << boolalpha << s.canJump(nums) << endl;

    return 0;
}
