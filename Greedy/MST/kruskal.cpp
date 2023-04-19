/*
Kruskals algorithm for finding the MST using Disjoint Set data structure.
Time complexity - O(ElogE) 
*/
#include <bits/stdc++.h>
#include "DisjointSet.h"
class Kruskals{
    public:
        void Findmst(){
            int nodes , edges;
            ifstream in("input.txt");
            in >> nodes >> edges;
            DisjointSet ds(nodes);
            vector<vector<int>> graph; //Graph for storing all the edges
            for(int i = 0 ; i < edges ; i++){
                int u , v , w; 
                in >> u >> v >> w;
                graph.push_back({w,u,v});
            }
            //sorting the edges on basis of their weights
            sort(graph.begin() , graph.end());
            int sum = 0;
            vector<pair<int,int>> MST;
            for(auto & i : graph){
                int w = i[0] , u = i[1] , v = i[2];
                //If they belong to the same component then skip
                if(ds.findUltimateParent(u) == ds.findUltimateParent(v)) continue;
                sum += w;
                //Making them in same component
                ds.Union(u,v);
                MST.push_back({u,v});
            }
            cout << "The MST sum is : " << sum << endl;
            for(auto & i : MST){
                cout << i.first << " " << i.second << endl;
            }
        }
};
int main(){
    Kruskals k;
    k.Findmst();
}