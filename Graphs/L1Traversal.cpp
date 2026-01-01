#include<iostream>
#include<queue>
#include<unordered_map>
#include<map>
#include<vector>
using namespace std;


 class Graph{
  public:
  //adjacency list
  unordered_map<int , vector<int> > adjList;
//   map<int , vector<int> > adjList;

  //direction = 1 -> directed edge
  //direction = 0 -- undirected edge
  void addEdge(int u, int v, bool direction){
    if(direction == 1){
        //directed edge -> u->v
        adjList[u].push_back(v);
    }
    else{
        //undirected edge
        //u--v equivalent to  u->v , v->u
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
  }

  void printAdjacencyList(){
    for(auto i : adjList){
        // i -> record or pair of key and value
        // i.first -> int
        // i.second -> vector<int>
        cout << i.first << ": ";
        cout << "{";
        for(auto j: i.second){
            cout << j <<", ";
        }
        cout << "}" << endl;
    }
  }

  void bfsTraversal(int src){
    queue<int> q;
    unordered_map<int,bool> visited;
    //initial state
    q.push(src);
    visited[src] = true;
    //main logic
    while(!q.empty()){
         int frontNode = q.front();
         q.pop();
         cout << frontNode << ", ";
         for(auto nbr: adjList[frontNode]){
            // hr ek nbr ko queue me insert krna hai but
            //insert tabhi karna hai, agar unvisited ho
            if(!visited[nbr]){
                q.push(nbr);
                visited[nbr] = true;
            }
         }
    }

  }

};


int main(){
    Graph g;    

    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 8, 1);
    g.addEdge(3, 4, 1);
    g.addEdge(8, 4, 1);
    g.addEdge(4, 5, 1);
    g.addEdge(4, 7, 1);
    g.addEdge(5, 6, 1);
    g.addEdge(7, 6, 1);
    
    g.printAdjacencyList();
    g.bfsTraversal(0);

    return 0;
}