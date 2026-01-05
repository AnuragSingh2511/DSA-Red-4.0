#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(int n, vector<int>& topoOrder) {
        
        queue<int> q;
        map<int,int> indegree;

        // initialize kardi indegree sabki
        for (auto i : adj) {
            for (auto nbr : i.second) {
                indegree[nbr]++;
            }
        }

        // push all zero indegree wali node into queue
        for (int node = 0; node<n; node++){
            if(indegree[node] == 0){
                q.push(node);
            }
        }

        // BFS chalate hai
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

    int main(){
        // l6 leetcode 

        return 0;
    }