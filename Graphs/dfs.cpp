#include <bits/stdc++.h>
#include <fstream>
using namespace std;

void dfs(int node , int parent , vector<int> adj[] , vector<int> & vis){
    vis[node] = 1;
    if(parent != -1){
        cout << parent << " " << node << endl;
    }
    for(auto & child : adj[node]){
        if(!vis[child]){
            dfs(child , node , adj , vis);
        }
    }
}
int main(){
    ifstream in("input.txt");
    int nodes , edges;
    in >> nodes >> edges;
    vector<int> adj[nodes];
    for(int i = 0 ; i < edges ; i++){
        int a,b; in >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> vis(nodes , 0);
    dfs(0 , -1 , adj , vis);
}