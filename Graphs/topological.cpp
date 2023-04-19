//Time complexity - O(V+E) we use BFS traversal and whichever node has indegree = 0 , we push it into our queue(Kahn's algorithm).
//Space complexity - O(V)

#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main(){
    ifstream in("input.txt");
    int nodes , edges;
    in >> nodes >> edges;
    vector<int> adj[nodes];
    vector<int> indeg(nodes , 0);
    for(int i = 0 ; i < edges ; i++){
        int a,b; in >> a >> b;
        adj[a].push_back(b);
        indeg[b]++;
    }
    queue<int> q;
    vector<int> ans;
    for(int i = 0 ; i < nodes ; i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }
    int cnt = 0;
    while(!q.empty()){
        int node = q.front();
        ans.push_back(node); 
        q.pop();
        cnt++;
        for(auto & child : adj[node]){
            indeg[child]--;
            if(indeg[child] == 0){
                q.push(child);
            }
        }
    }
    if(cnt != nodes){
        cout << "The given graph is not a directed acyclic graph and hence no topological ordering is possible" << endl;
    }
    else {
        for(auto & i : ans){
            cout << i << " ";
        }
        cout << endl;
    }
}