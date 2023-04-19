//Time complexity - O((n+26)*d) where d is the size of each string
//space - O(n)
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
void countSort(string arr[] , int n , int curr){
    int count[26] = {0};
    for(int i = 0 ; i < n ; i++){
        if(curr > arr[i].size()-1){
            count[arr[i][arr[i].size()-1]-'a']++;
        }
        else{
            count[arr[i][curr]-'a']++;
        }
    }
    for(int i = 1 ; i < 26 ; i++){
        count[i] += count[i-1];
    }
    string ans[n];
    for(int i = n-1 ; i >= 0 ; i--){
        if(curr > arr[i].size()-1){
            ans[count[arr[i][arr[i].size()-1]-'a']-1] = arr[i];
            count[arr[i][arr[i].size()-1]-'a']--;
        }
        else{
            ans[count[arr[i][curr]-'a']-1] = arr[i];
            count[arr[i][curr]-'a']--;
        }
    }
    for(int i = 0 ; i < n ; i++){
        arr[i] = ans[i];
    }
}
int main(){
    int n;
    ifstream in("input.txt");
    in >> n;
    string arr[n];
    int maxi = 0;
    for(int i = 0 ; i < n ; i++){
        in >> arr[i];
        if(arr[i].size() > maxi) maxi = arr[i].size();
    }
    int curr = maxi-1;
    while(curr > -1){
        countSort(arr , n , curr);
        curr--;
    }
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
}