//Time complexity - O(N + E) we use bfs traversal to check for bipartiteness. 
// Space complexity - O(V)
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
bool help(int src , vector<int>  adj[] , vector<int>& color){
    queue<int> q;
    q.push(src);
    color[src] = 0;
    while(!q.empty()){
        int par = q.front();
        q.pop();
        for(auto & child : adj[par]){
            if(color[child] == -1){
                //giving an opposite color of parent to child.
                color[child] = !color[par];
                q.push(child);
            }
            //If the child node is already colored(It will only happen in the case of a cycle) and the color of both parent and child are same so we return false.
            else if(color[child] == color[par]) return false;
        }
    }
    return true;
}
int main(){
    ifstream in("input.txt");
    int nodes , edges;
    in >> nodes >> edges;
    vector<int> adj[nodes];
    for(int i = 0 ; i < nodes ; i++){
        int a,b; in >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> color(nodes , -1);
    for(int i = 0 ; i < nodes ; i++){
        if(color[i] == -1){
            if(!help(i , adj , color)){
                cout << "The given graph is not bipartite" << endl;
                return 0;
            }
        }
    }
    cout << "The given graph is bipartite" << endl;
}