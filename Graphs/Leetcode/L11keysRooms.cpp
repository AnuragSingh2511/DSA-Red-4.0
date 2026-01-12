#include <bits/stdc++.h>
using namespace std;

// T.C - O(N + E)
// S.C - O(N)
//
// N = number of rooms
// E = total number of keys

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        int visitedNodeCount = 0;
        queue<int> q;
        unordered_map<int, bool> visited;

        int src = 0;

        // initial state
        q.push(src);
        visited[src] = true;
        visitedNodeCount++;

        // BFS
        while(!q.empty()){
            int front = q.front();
            q.pop();

            for(auto nbr : rooms[front]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                    visitedNodeCount++;
                }
            }
        }

        return visitedNodeCount == n;
    }
};

int main() {

    /*
    Sample Input:
    4
    1 1
    1 2
    1 3
    0    

    Sample Output:
    true
    */

    int n;
    cin >> n;

    vector<vector<int>> rooms(n);
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;   // number of keys in room i
        rooms[i].resize(k);
        for(int j = 0; j < k; j++){
            cin >> rooms[i][j];
        }
    }

    Solution s;
    cout << "Output: " << boolalpha << s.canVisitAllRooms(rooms) << endl;


    return 0;
}
