#include <bits/stdc++.h>
using namespace std;

// T.C - O(log N)
// S.C - O(1)

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s = 0;
        int e = arr.size() - 1;

        // binary search
        while(s < e){
            int mid = s + (e - s) / 2;

            if(arr[mid] < arr[mid + 1]){
                // peak lies on right side
                s = mid + 1;
            }
            else{
                // peak is mid or on left side
                e = mid;
            }
        }
        // s == e -> peak index
        return s;
    }
};

int main() {

    /*
    Sample Input:
    7
    0 2 4 6 5 3 1

    Sample Output:
    3

    Explanation:
    Peak element = 6 at index 3
    */

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    Solution s;
    cout << "Output: " << s.peakIndexInMountainArray(arr) << endl;

    return 0;
}
