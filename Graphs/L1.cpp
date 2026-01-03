#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
using namespace std;

//Weighted graph
class Graph{
  public:
  //adjacency list
  unordered_map<int , vector<pair<int,int> > > adjList;

  //direction = 1 -> directed edge
  //direction = 0 -- undirected edge
  void addEdge(int u, int v, int wt, bool direction){
    if(direction == 1){
        //directed edge -> u->v
        // u -> (v, wt)
        adjList[u].push_back(make_pair(v,wt));
    }
    else{
        //undirected edge
        //u--v equivalent to  u->(v,wt) , v->(u,wt)
        adjList[u].push_back(make_pair(v,wt));
        adjList[v].push_back(make_pair(u,wt));
    }
  }

  void printAdjacencyList(){
    for(auto i : adjList){
        // i -> record or pair of key and value
        // i.first -> int
        // i.second -> vector<pair<int,int>>
        cout << i.first << ": ";
        cout << "{";
        for(auto j: i.second){
            //j -> pair<int,int>
            //j.first represents "v"
            //j.second represents "wt"
            cout << "(" << j.first <<"," << j.second << "), ";
        }
        cout << "}" << endl;
    }
  }


};

//  class Graph{
//   public:
//   //adjacency list
//   unordered_map<int , vector<int> > adjList;

//   //direction = 1 -> directed edge
//   //direction = 0 -- undirected edge
//   void addEdge(int u, int v, bool direction){
//     if(direction == 1){
//         //directed edge -> u->v
//         adjList[u].push_back(v);
//     }
//     else{
//         //undirected edge
//         //u--v equivalent to  u->v , v->u
//         adjList[u].push_back(v);
//         adjList[v].push_back(u);
//     }
//   }

//   void printAdjacencyList(int n){
//     for(int i = 0; i<n ; i++){
//         // i -> record or pair of key and value
//         // i.first -> int
//         // i.second -> vector<int>
//         cout << i << ": ";
//         cout << "{";
//         for(auto j: adjList[i]){
//             cout << j <<", ";
//         }
//         cout << "}" << endl;
//     }
//   }


// };


int main(){
    Graph g;
    //weighted graph through adjacency list
    g.addEdge(0, 1, 10, 1);
    g.addEdge(1, 2, 20, 1);
    g.addEdge(2, 3, 30, 1);
    g.addEdge(3, 4, 40, 1);
    
    
    g.printAdjacencyList();

    // g.addEdge(0, 1, 1);
    // g.addEdge(1, 2, 1);
    // g.addEdge(2, 3, 1);
    // g.addEdge(3, 4, 1);
    // //graph looks like 0->1->2->3->4
    // g.printAdjacencyList(5);

    return 0;
}