#include<iostream>
#include<list>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;

//T.C - O(V + E) , S.C - O(V+E)
class Graph{
    public:
    unordered_map<int , list<int> > adj;

    void addEdge(int u, int v, bool direction){
        //direction = 0 -> undirected graph
        //direction = 1 -> directed graph
        if(direction == 0){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        else{
            adj[u].push_back(v);
        }
    }
    void printAdjList(int n){
        for(int i = 0; i < n; i++){
          cout << i << ": {";
          for(auto j : adj[i]){
            cout << j << ", ";
          }
          cout << "}" << endl;
        }
    }

    void shortestPathbfs(int src, int dest){
        unordered_map<int,bool> visited;
        unordered_map<int,int> parent;
        queue<int> q;

        //initial state
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        //main logic
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            for(auto nbr: adj[frontNode]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = frontNode;
                }
            }
        }
        //parent array ready
        vector<int> path;

        int node = dest;

        while(node != -1){
            path.push_back(node);
            node = parent[node];
        }

        //reverse path
        reverse(path.begin() , path.end());

        //print path
        cout << "Printing path: " ;
        for(auto i: path){
            cout << i << "->";
        } cout << endl;

    }
};


int main(){

    Graph g;

    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,3,0);
    g.addEdge(2,4,0);
    g.addEdge(4,5,0);
    g.addEdge(5,3,0);
    
    int src = 0;
    int dest = 3;

    g.shortestPathbfs(src,dest);
    

    return 0;
}