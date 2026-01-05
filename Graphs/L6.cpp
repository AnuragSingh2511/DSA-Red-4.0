#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

class Graph {
public:
    unordered_map<int, list<int>> adjList;

    // TC: O(1)
    // SC: O(1)
    void addEdge(int u, int v) {
        // v -> u (prerequisite logic)
        adjList[v].push_back(u);
    }
};

class Solution {
public:
    // TC: O(N + E)  //N = number of courses
                     //E = number of prerequisites (edges)
    // SC: O(N + E)

    //topoSortDfs also another way of doing it
    void topoSortBfs(int n, vector<int>& topoOrder, unordered_map<int, list<int>>& adjList) {

        queue<int> q;
        vector<int> indegree(n, 0);

        // calculate indegree
        for (auto i : adjList) {
            for (auto nbr : i.second) {
                indegree[nbr]++;
            }
        }

        // push all nodes with indegree 0
        for (int node = 0; node < n; node++) {
            if (indegree[node] == 0) {
                q.push(node);
            }
        }

        // Kahn's Algorithm
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

    // TC: O(N + E)
    // SC: O(N + E)
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        Graph g;

        // add edges
        for (auto i : prerequisites) {
            g.addEdge(i[0], i[1]);
        }

        vector<int> topoOrder;
        topoSortBfs(numCourses, topoOrder, g.adjList);

        return topoOrder.size() == numCourses;
    }
};

int main() {
    Solution s;

    int numCourses = 4;
    vector<vector<int>> prerequisites = {
        {1, 0},
        {2, 1},
        {3, 2}
    };

    if (s.canFinish(numCourses, prerequisites)) {
        cout << "YES, all courses can be finished" << endl;
    } else {
        cout << "NO, cycle detected" << endl;
    }

    return 0;
}
