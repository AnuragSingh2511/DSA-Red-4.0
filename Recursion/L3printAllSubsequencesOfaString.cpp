#include <bits/stdc++.h>
using namespace std;

// T.C - O(2^n * n)
// S.C - O(n)   // recursion stack (excluding output storage)

class Solution {
public:
    void solve(string s, int index, string output, vector<string> &ans){
        // base case
        if(index >= s.length()){
            ans.push_back(output);
            return;
        }

        char ch = s[index];

        // include
        output.push_back(ch);
        solve(s, index + 1, output, ans);

        // backtrack
        output.pop_back();

        // exclude
        solve(s, index + 1, output, ans);
    }

    vector<string> generateAllSubsequences(string s) {
        vector<string> ans;
        int index = 0;
        string output = "";

        solve(s, index, output, ans);

        // sort before returning
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {

    /*
    Sample Input:
    abc

    Sample Output:
    
    (empty)
    a
    ab
    abc
    ac
    b
    bc
    c
    */

    string s;
    cin >> s;

    Solution sol;
    vector<string> result = sol.generateAllSubsequences(s);

    for(auto &str : result){
        if(str == "")
            cout << "(empty)";
        else
            cout << str;
        cout << endl;
    }

    return 0;
}
