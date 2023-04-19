/*
Prims algo for finding Minimum spannning tree
time complexity - O(Elog(E))
*/

#include <bits/stdc++.h>
using namespace std;
class Prim{
    vector<pair<int,int>> * adj;
    int nodes , edges;
    public:
    //Making adjacency list for graph
    void makegraph(){
        ifstream in("input.txt");
        in >> nodes >> edges;
        adj = new vector<pair<int,int>>[nodes+1];
        for(int i = 0 ; i < edges ; i++){
            int u , v , wt;
            in >> u >> v >> wt;
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
    }
    void findMst(){
        //A minimum priority queue of vector of int of size 3 where 1st integer denotes the weight , second the node , and third node's parent
        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> q;
        vector<bool> visited(nodes,0);
        q.push({0 , 1 , 0});
        //MST array
        vector<pair<int,int>> MST;
        int sum = 0;
        while(!q.empty()){
            int u = q.top()[1];
            int v = q.top()[2];
            int w = q.top()[0];
            q.pop();
            if(visited[u]) continue;
            visited[u] = 1;
            cout << u << " " << v << " " << w << endl;
            if(v != 0)MST.push_back({u,v});
            sum += w;
            for(auto & i : adj[u]){
                int nbr = i.first;
                int edgewt = i.second;
                if(!visited[nbr]){
                    q.push({edgewt , nbr , u});
                }
            }
        }
        cout << "The MST sum is : " << sum << endl;
        for(auto & edge : MST){
            cout << edge.first << " " << edge.second << endl;
        }
    }
};
int main(){
    Prim p;
    p.makegraph();
    p.findMst();
}