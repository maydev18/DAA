//The following code check if given graph is strongly connected or not using kosaraju's Algorithm
//Time complexity- O(V+E)   (2 DFS traversals);
//Space complexity - O(V+E) (for storing the reverse of graph)
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
void dfs(int node , vector<int> graph[] , vector<bool> & vis){
    vis[node] = 1;
    for(auto & child : graph[node]){
        if(!vis[child]){
            dfs(child , graph , vis);
        }
    }
}
int main(){
    ifstream in("input.txt");
    int nodes , edges;
    in >> nodes >> edges;
    vector<int> graph[nodes];
    vector<int> rev_graph[nodes];
    for(int i = 0 ; i < edges ; i++){
        int a,b; in >> a >> b;
        graph[a].push_back(b);
        rev_graph[b].push_back(a);
    }
    vector<bool> vis(nodes , 0);
    //first dfs

    dfs(0 , graph , vis);
    for(int i = 0 ;  i < nodes ; i++){
        if(!vis[i]){
            cout << "The graph is not strongly 1 connected " << endl;
            return 0;
        }
    }
    for(int i = 0 ; i < nodes ; i++){
        vis[i] = 0;
    }
    //second dfs

    dfs(0 , rev_graph , vis);
    for(int i = 0 ;  i < nodes ; i++){
        if(!vis[i]){
            cout << "The graph is not strongly 2 connected " << endl;
            return 0;
        }
    }
    //If all the vertex were visited in both dfs traversals it means the graph is strongly connected
    cout << "The graph is strongly connected " << endl;
    return 0;
}