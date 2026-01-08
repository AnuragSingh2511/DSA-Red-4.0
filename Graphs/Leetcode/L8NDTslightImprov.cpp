#include <bits/stdc++.h>
using namespace std;

// T.C - O(E log V)
// S.C - O(V + E)

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
/*
INTERVIEW ONE-LINER

“This is Dijkstra’s algorithm using a min-heap, giving O(E log V) time and O(V + E) space complexity"
*/
        vector<vector<pair<int,int>>> adjList(n + 1);

        for (auto i : times) {
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            adjList[u].push_back({v, wt});
        }

        // Min Heap {timeSoFar, node}
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        pq.push({0, k});

        unordered_map<int, bool> visited;
        int visitedNodeCount = 0;
        int timeAns = 0;

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int currTime = top.first;
            int currNode = top.second;

            if (visited[currNode] == true) {
                continue;
            }

            visited[currNode] = true;
            visitedNodeCount++;
            timeAns = max(timeAns, currTime);

            for (auto j : adjList[currNode]) {
                // j.first -> int -> node
                // j.second -> int -> time/weights
                int nbrNode = j.first;
                if (visited[nbrNode] == false) {
                    int edgeKaUparKaTime = j.second;
                    pq.push({currTime + edgeKaUparKaTime, nbrNode});
                }
            }
        }

        if (visitedNodeCount == n)
            return timeAns;
        else
            return -1;
    }
};

int main() {

    Solution s;   // object creation to access non-static member function

    int n, k, e;
    cin >> n >> e >> k;
    /*
    4 3 2
    2 1 1
    2 3 1
    3 4 1

    o/p -> 2
    */

    vector<vector<int>> times(e, vector<int>(3));
    for (int i = 0; i < e; i++) {
        cin >> times[i][0] >> times[i][1] >> times[i][2];
    }

    cout << s.networkDelayTime(times, n, k);

    return 0;
}
