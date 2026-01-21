#include <bits/stdc++.h>
using namespace std;

// T.C - O(n^n)   (exponential: tries all jump possibilities)
// S.C - O(n)     (recursion stack)

class Solution {
public:
    void solve(vector<int>& nums, int i, int &ans, int step){
        // reached last index
        if(i == nums.size() - 1){
            ans = min(ans, step);
            return;
        }

        // invalid index
        if(i > nums.size() - 1) return;

        // try all jumps from current index
        for(int jump = 1; jump <= nums[i]; jump++){
            solve(nums, i + jump, ans, step + 1);
        }
    }

    int jump(vector<int>& nums) {
        int ans = INT_MAX;
        solve(nums, 0, ans, 0);
        return ans;
    }
};

int main() {

    /*
    Sample Input:
    5
    2 3 1 1 4

    Sample Output:
    2

    Explanation:
    0 -> 1 -> 4
    */

    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    Solution s;
    cout << "Output: " << s.jump(nums) << endl;

    return 0;
}
