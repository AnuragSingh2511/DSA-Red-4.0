#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC: O(N + E)
    // SC: O(N + E)
    void topoSortBfs(int n, vector<int>& topoOrder,
                     unordered_map<int, list<int>>& adjList) {

        queue<int> q;
        vector<int> indegree(n, 0);

        for (auto i : adjList) {
            for (auto nbr : i.second) {
                indegree[nbr]++;
            }
        }

        for (int node = 0; node < n; node++) {
            if (indegree[node] == 0) {
                q.push(node);
            }
        }

        while (!q.empty()) {
            int frontNode = q.front();
            q.pop();
            topoOrder.push_back(frontNode);

            for (auto nbr : adjList[frontNode]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adjList;

        for (auto i : prerequisites) {
            adjList[i[1]].push_back(i[0]);
        }

        vector<int> topoOrder;
        topoSortBfs(numCourses, topoOrder, adjList);

        if (topoOrder.size() == numCourses)
            return topoOrder;
        else
            return {};
    }
};

// 🔥 THIS IS WHAT WAS MISSING
int main() {
    Solution s;

    int numCourses = 4;
    vector<vector<int>> prerequisites = {
        {1, 0},
        {2, 1},
        {3, 2}
    };

    vector<int> ans = s.findOrder(numCourses, prerequisites);

    if (ans.empty()) {
        cout << "Cycle detected. No valid order.\n";
    } else {
        cout << "Valid course order: ";
        for (int x : ans) cout << x << " ";
        cout << endl;
    }

    return 0;
}
