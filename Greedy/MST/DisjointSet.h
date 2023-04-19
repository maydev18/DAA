/*
Disjoint set data structure for finding if two nodes belong to the same component or not
Time complexity - O(4α) = O(1)
*/
#include <bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int> size;
    vector<int> ultimate_parent;
    public:
    //initialization
    DisjointSet(int n){
        size.resize(n+1);
        ultimate_parent.resize(n+1);
        for(int i = 0 ; i <= n ; i++){
            ultimate_parent[i] = i;
            size[i] = 1;
        }
    }
    //Path compression
    int findUltimateParent(int u){
        if(u == ultimate_parent[u]){
            return u;
        }
        return ultimate_parent[u] = findUltimateParent(ultimate_parent[u]);
    }
    //Union by size
    void Union(int u , int v){
        int par_u = findUltimateParent(u);
        int par_v = findUltimateParent(v);
        if(par_u == par_v) return;
        if(size[par_u] > size[par_v]){
            ultimate_parent[par_v] = par_u;
            size[par_u] += size[par_v];
        }
        else{
            ultimate_parent[par_u] = par_v;
            size[par_v] += size[par_u];
        }
    }
};