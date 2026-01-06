#include <bits/stdc++.h>
using namespace std;

// TC: O(N * M)
// SC: O(N * M)

class Solution {
public:

    bool isSafe(int newX, int newY, vector<vector<int>> temp){
        if(newX >= 0 && newY >= 0 && newX < temp.size() && newY < temp[0].size() && temp[newX][newY] == 1){
            return true;
        }
        else{
            return false;
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        //pair<int, int> -> coordinates
        //second member -> int -> time
        queue<pair < pair<int, int>, int> > q;
        vector<vector<int>> temp = grid; 
        int minTime = 0;

        int n = grid.size();
        int m = grid[0].size();

        // find all rotten oranges
        for(int i = 0; i<n; i++){
            for(int j =0; j<m; j++){
                if(temp[i][j] == 2){
                    q.push({{i,j}, 0});
                }
            }
        }

        // bfs
        while(!q.empty()){
            auto frontNodePair = q.front();
            q.pop();

            auto frontNodeCoordinates = frontNodePair.first;
            int frontNodeTime = frontNodePair.second;
            int tempX = frontNodeCoordinates.first;
            int tempY = frontNodeCoordinates.second;

            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};

            for(int i=0; i<4; i++){
                int newX = tempX + dx[i];
                int newY = tempY + dy[i];

                if(isSafe(newX,newY,temp)){
                    q.push({{newX,newY}, frontNodeTime+1});
                    minTime = max(minTime, frontNodeTime+1);
                    temp[newX][newY] = 2;
                }
            }
        }

        // check fresh oranges
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(temp[i][j] == 1){
                    return -1; 
                }
            }
        }
        return minTime;
    }
};

int main() {

    Solution s;   // object creation to access non-static member functions

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    cout << s.orangesRotting(grid);

    return 0;
}
