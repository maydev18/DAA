//Time complexity - O(n+k) where k is the maximum number in array
//space complexity - O(k)
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    ifstream in("input.txt");
    in >> n;
    int arr[n];
    int maxi = -1e9;
    int mini = 1e9;
    for(int i = 0 ; i < n ; i++){
        in >> arr[i];
        maxi = max(maxi , arr[i]);
        mini = min(mini , arr[i]);
    }
    if(mini >= 0){
        int count[maxi+1] = {0};
        for(int i = 0 ; i < n ; i++){
            count[arr[i]]++;
        }
        // unstable algorithm
        // int i = 0 , j = 0;
        // while(i < n && j <= maxi){
        //     if(count[j] != 0){
        //         arr[i] = j;
        //         count[j]--;
        //         i++;
        //     }
        //     else{
        //         j++;
        //     }
        // }

        for(int i = 1 ; i <= maxi ; i++){
            count[i] += count[i-1];
        }
        int ans[n];
        for(int i = n-1 ; i >= 0 ; i--){
            //since arrays are 0 indexed
            ans[count[arr[i]]-1] = arr[i];
            count[arr[i]]--;
        }
        for(int i = 0 ; i < n ; i++){
            cout << ans[i] << endl;
        }
    }
    else{
        int count[maxi-mini+1] = {0};
        for(int i = 0 ; i < n ; i++){
            count[arr[i]-mini]++;
        }
        for(int i = 1 ; i <= maxi-mini ; i++){
            count[i] += count[i-1];
        }
        int ans[n];
        for(int i = n-1 ; i >= 0 ; i--){
            //since arrays are 0 indexed
            ans[count[arr[i]-mini]-1] = arr[i];
            count[arr[i]-mini]--;
        }
        for(int i = 0 ; i < n ; i++){
            cout << ans[i] << endl;
        }
    }
}