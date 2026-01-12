#include <bits/stdc++.h>
using namespace std;

// T.C - O(V + E)
// S.C - O(V)

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        unordered_map<int, bool> vis;
        unordered_map<int, int> colorOfNode; // -1 uncolored, 0 red, 1 blue
        queue<int> q;

        // initialize
        for(int i = 0; i < n; i++){
            vis[i] = false;
            colorOfNode[i] = -1;
        }

        // handle disconnected components
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                // start BFS from node i
                q.push(i);
                vis[i] = true;
                colorOfNode[i] = 0;

                while(!q.empty()){
                    int front = q.front();
                    q.pop();

                    for(auto nbr : graph[front]){
                        if(!vis[nbr]){
                            q.push(nbr);                       // FIXED
                            vis[nbr] = true;
                            colorOfNode[nbr] = !colorOfNode[front];
                        }
                        else if(colorOfNode[nbr] == colorOfNode[front]){
                            return false;                      // conflict
                        }
                    }
                }
            }
        }
        return true;
    }
};

int main() {

    /*
    Sample Input:
    4
    2 1 3
    2 0 2
    2 1 3
    2 0 2

    Meaning:
    0 -> [1, 3]
    1 -> [0, 2]
    2 -> [1, 3]
    3 -> [0, 2]

    Sample Output:
    true
    */

    int n;
    cin >> n;

    vector<vector<int>> graph(n);
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;              // number of neighbours of node i
        graph[i].resize(k);
        for(int j = 0; j < k; j++){
            cin >> graph[i][j];
        }
    }

    Solution s;
    cout << "Output: " << boolalpha << s.isBipartite(graph) << endl;

    return 0;
}
