#include<iostream>
#include<list>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<stack>
#include<limits.h>
using namespace std;

// Time Complexity: O(V + E)
// Space Complexity: O(V + E)

//GFG - Shortest path in Directed Acyclic Graph

class Graph{
    public:
    unordered_map<int , list<pair<int ,int> > > adj;

    void addEdge(int u, int v, int wt, bool direction){
        //direction = 0 -> undirected graph
        //direction = 1 -> directed graph
        if(direction == 0){
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        else{
            adj[u].push_back({v,wt});
        }
    }   

    void topoSortdfs(int src, unordered_map<int,bool> &visited, stack<int> &ans){
        visited[src] = true;

        for(auto neighbour: adj[src]){
            if(!visited[neighbour.first]){
                topoSortdfs(neighbour.first, visited, ans);
            }
        }

        //while returning, store the node in stack
        // cout << "Pushing " << src << endl;
        ans.push(src);
    }

    void shortestPathdfs(int src){
        stack<int> topoOrder;
        unordered_map<int,bool> visited;

        topoSortdfs(src, visited, topoOrder);

        // ab mere paas topo order ka stack ready hai
        int n = topoOrder.size();
        vector<int> dist(n, INT_MAX);

        //initial state maintain
        src = topoOrder.top();
        topoOrder.pop();
        dist[src] = 0;
        // and src ke nbrs ke minimum dist ko update krte ho

        for(auto nbr: adj[src]){
           //nbr -> {a,b}
           // a -> node
           // b -> weight
           int node = nbr.first;
           int weightDistance =  nbr.second;

           if(dist[src] + weightDistance < dist[node]){
            dist[node] = dist[src] + weightDistance;
           }
        }

       //main logic
    while(!topoOrder.empty()){
        int frontNode = topoOrder.top();
        topoOrder.pop();

        for(auto nbr: adj[frontNode]){
            //nbr -> {a,b}
           // a -> node
           // b -> weight
           int node = nbr.first;
           int weightDistance =  nbr.second;

           if(dist[frontNode] + weightDistance < dist[node]){
            dist[node] = dist[frontNode] + weightDistance;
           }
        }
    }

    cout << "Printing Distance array : " << endl;

    for(auto i: dist){
        cout << i << " ";

    }cout << endl;

    }
};


int main(){

    Graph g;

    g.addEdge(0,1,5,1);
    g.addEdge(0,2,13,1);
    g.addEdge(0,4,3,1);
    g.addEdge(1,2,7,1);
    g.addEdge(1,4,1,1);    
    g.addEdge(4,3,6,1);    
    g.addEdge(3,2,2,1);  

    g.shortestPathdfs(0);
    

    return 0;
}