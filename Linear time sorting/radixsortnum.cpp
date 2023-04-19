//Time complexity - O((n+10)*d) where d is the maximum number of digits in any number
//space - O(n)
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
void countSort(int arr[] , int n , int exp){
    int count[10] = {0};
    for(int i = 0 ; i < n ; i++){
        count[(arr[i]/exp)%10]++;
    }
    for(int i = 1 ; i < 10 ; i++){
        count[i] += count[i-1];
    }
    int ans[n];
    for(int i = n-1 ; i >= 0 ; i--){
        ans[count[(arr[i]/exp)%10]-1] = arr[i];
        count[(arr[i]/exp)%10]--;
    }
    for(int i = 0 ; i < n ; i++){
        arr[i] = ans[i];
    }
}
int main(){
    int n;
    ifstream in("input.txt");
    in >> n;
    int arr[n];
    int maxi = -1e9;
    for(int i = 0 ; i < n ; i++){
        in >> arr[i];
        maxi = max(maxi , arr[i]);
    }
    int exp = 1;
    while(maxi/exp > 0){
        countSort(arr , n , exp);
        exp *= 10;
    }
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
}