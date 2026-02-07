#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

// Global copy for comparator
string orderCopy;

// T.C - O(N log N * M)
// S.C - O(1)

class Solution {
public:
    static bool cmp(char ch1, char ch2){
        return (orderCopy.find(ch1) < orderCopy.find(ch2));
    } 

    string customSortString(string order, string s) {
        orderCopy = order;
        sort(s.begin(), s.end(), cmp);
        return s;
    }
};

int main() {

    /*
    Sample Input:
    cba
    abcd

    Sample Output:
    cbad
    */

    string order, s;
    cin >> order >> s;

    Solution sol;
    cout << "Output: " << sol.customSortString(order, s) << endl;

    return 0;
}
