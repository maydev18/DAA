#include <bits/stdc++.h>
#include <fstream>
using namespace std;

void bfs(int src  , vector<int> adj[] , int nodes){
    vector<int> vis(nodes , 0);
    vis[src] = 1;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            int node = q.front();
            cout << node << " ";
            q.pop();
            for(auto & child : adj[node]){
                if(!vis[child]){
                    vis[child] = 1;
                    q.push(child);
                }
            }
        }
        cout << endl;
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
    bfs(0 , adj , nodes);
}