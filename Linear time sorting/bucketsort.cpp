#include <fstream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    ifstream in("bucketinput.txt");
    in >> n;
    float arr[n];
    for(int i = 0 ; i < n ; i++){
        in >> arr[i];
    }
    vector<float> buckets[n];
    for(int i = 0 ; i < n ; i++){
        buckets[(int)(n*arr[i])].push_back(arr[i]);
    }
    for(int i = 0 ; i < n ; i++){
        sort(buckets[i].begin(),buckets[i].end());
    }
    int curr = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < buckets[i].size() ; j++){
            arr[curr++] = buckets[i][j];
        }
    }
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }

}