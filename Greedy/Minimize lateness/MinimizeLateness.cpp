/*
Given n jobs with their time interval and lateness. Schedule them in such a way that the maximum lateness among all jobs is minimized(Minimize the maximum lateness)
Time complexity - O(n * logn)
Space - O(1)
*/
#include <bits/stdc++.h>
using namespace std;
class MinimizeLateness{
    public:
        void findOptimal(){
            //input file contains n the total number of jobs, then n line contains job with first integer denoting the duration and second denoting the deadline
            int n;
            ifstream in("input.txt");
            in >> n;
            vector<pair<int,int>> v;
            for(int i = 0 ; i < n ; i++){
                int di,ti; 
                in >> ti >> di;
                v.push_back({di,ti});
            }
            //sorting them on the basis of their deadline.
            sort(v.begin() , v.end());
            cout << "The jobs to be scheduled are: " << endl << endl;
            cout << "time-interval" << "  " << "deadline" << endl;
            for(auto & i : v){
                cout << "   " << i.second << '\t'<<'\t' << i.first << endl;
            }
            int tt = 0;
            int max_lateness = 0;
            //finding the maximum lateness
            for(auto & i : v){
                int di = i.first , ti = i.second;
                tt += ti;
                if(tt > di){
                    max_lateness = max(max_lateness , tt-di);
                }
            }
            cout << "The maximum lateness is : " << max_lateness << endl;
        }
};
int main(){
    MinimizeLateness m;
    m.findOptimal();
}