/*
The following code calculates the shortest path from a given source node to all other nodes using Dijkstra algorithm.
Time complexity- Elog(V) where E is the number of edges and V is the number of vertices in the graph
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream in("input.txt");
    //first line of input file contains the number of nodes(starting from 1) and edges.
    //Then each line contains an edges with a initial vertex , final vertex and edge weight
    int nodes , edges; in >> nodes >> edges;

    vector<pair<int,int>> adj[nodes+1]; // Adjacency list
    for(int i = 0  ; i < edges ; i++){
        int u , v , w; in >> u >> v >> w;
        adj[u].push_back({v,w});
    }
    vector<int> dist(nodes+1 , INT_MAX);
    dist[1] = 0;
    //Minimum priority queue
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
    pq.push({0,1});
    int itr = 0;
    while(!pq.empty()){
        if(itr == nodes) break; // A small optimization so that outer loop runs for only 'nodes' number of times
        int u = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        for(auto & edge : adj[u]){
            int v = edge.first , weight = edge.second;
            if(dist[v] > cost + weight){
                dist[v] = cost+weight;
                pq.push({dist[v] , v});
            }
        }
        itr++;
    }
    for(int i = 1 ; i <= nodes ; i++){
        cout << dist[i] << " ";
    }
    cout << endl;
}