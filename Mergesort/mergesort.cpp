//this program is of merge sort.
//it is used to sort a given array using divide and conquer technique
//time complexity = O(n*logn)
//space = O(n)
#include <iostream>
#include <time.h>
#include <fstream>
using namespace std;
int steps = 0;
//time complexity = O(n)
void merge(int arr[] , int l , int r , int mid){
    if(arr[mid] <= arr[mid+1]){
        steps++;
        return;
    }
    int * temp = new int[r-l+1];
    int a = l , b = mid+1 , c = 0;
    while(a <= mid && b <= r){
        steps++;
        if(arr[a] > arr[b]){
            temp[c++] = arr[b++];
        }
        else{
            temp[c++] = arr[a++];
        }
    }
    while(a <= mid){
        steps++;
        temp[c++] = arr[a++];
    }
    while(b <= r){
        steps++;
        temp[c++] = arr[b++];
    }
    for(int i = l ; i <= r ; i++){
        steps++;
        arr[i] = temp[i-l];
    }
}
//time complexity = O(nlogn)
void mergesort(int arr[] , int l , int r){
    steps++;
    if(l >= r) return;
    int mid = l + (r-l)/2;
    mergesort(arr , l , mid);
    mergesort(arr , mid+1 , r);
    merge(arr , l , r , mid);
}
void display(int arr[] , int n){
    for(int i = 0 ; i < n ; i++) cout << arr[i] << " ";
    cout << endl;
}
int main(){
    srand(time(0));
    ofstream out;
    out.open("operations.txt");
    for(int i = 1 ; i <= 1000 ; i++){
        int arr[i];
        for(int j = 0 ; j < i ;j++){
            arr[j] = j;
        }
        mergesort(arr , 0 , i-1);
        int best = steps;
        steps = 0;
        for(int j = 0 ; j < i ; j++){
            arr[j] = rand()%100;
        }
        mergesort(arr , 0 , i-1);
        int avg = steps;
        steps = 0;
        out << i << " " << best << " " << avg << "\n";
    }
    return 0;
}