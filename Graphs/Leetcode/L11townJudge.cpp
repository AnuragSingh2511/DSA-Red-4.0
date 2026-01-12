#include <bits/stdc++.h>
using namespace std;

// T.C - O(n + trust.size())
// S.C - O(n)

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, int> indegree;
        unordered_map<int, int> outdegree;

        // initialise indegree and outdegree
        for(int i = 1; i <= n; i++){
            indegree[i] = 0;
            outdegree[i] = 0;
        }

        // calculate indegree and outdegree
        for(auto i : trust){
            int u = i[0];
            int v = i[1];
            indegree[v]++;
            outdegree[u]++;
        }

        // find judge
        for(int i = 1; i <= n; i++){
            if(indegree[i] == n - 1 && outdegree[i] == 0){
                return i;
            }
        }

        return -1;
    }
};

int main() {

    /*
    Sample Input:
    3 2
    1 3
    2 3

    Sample Output:
    3
    */

    int n, m;
    cin >> n >> m;

    vector<vector<int>> trust(m, vector<int>(2));
    for(int i = 0; i < m; i++){
        cin >> trust[i][0] >> trust[i][1];
    }

    Solution s;
    cout << s.findJudge(n, trust);

    return 0;
}
