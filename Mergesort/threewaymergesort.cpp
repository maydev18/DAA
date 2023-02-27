#include <iostream>
#include <time.h>
#include <fstream>
using namespace std;
int steps = 0;
void merge(int arr[] , int l , int r , int mid1 , int mid2){
    int * temp = new int[r-l+1];
    int a = l , b = mid1+1 , c = mid2+1 , x = 0;
    while(a <= mid1 && b <= mid2 && c <= r){
        steps++;
        if(arr[a] <= arr[b] && arr[a] <= arr[c]){
            temp[x++] = arr[a++];
        }
        else if(arr[b] <= arr[a] && arr[b] <= arr[c]){
            temp[x++] = arr[b++];
        }
        else{
            temp[x++] = arr[c++];
        }
    }
    while(a <= mid1 && b <= mid2){
        steps++;
        if(arr[a] < arr[b]){
            temp[x++] = arr[a++];
        }
        else{
            temp[x++] = arr[b++];
        }
    }
    while(a <= mid1 && c <= r){
        steps++;
        if(arr[a] < arr[c]){
            temp[x++] = arr[a++];
        }
        else{
            temp[x++] = arr[c++];
        }
    }
    while(b <= mid2 && c <= r){
        steps++;
        if(arr[b] < arr[c]){
            temp[x++] = arr[b++];
        }
        else{
            temp[x++] = arr[c++];
        }
    }
    while(a <= mid1){
        steps++;
        temp[x++] = arr[a++];
    }
    while(b <= mid2){
        steps++;
        temp[x++] = arr[b++];
    }
    while(c <= r){
        steps++;
        temp[x++] = arr[c++];
    }
    for(int i = l ; i <= r ; i++){
        steps++;
        arr[i] = temp[i-l];
    }
}
void mergesort(int arr[] , int l , int r){
    steps++;
    if(l >= r) return;
    int mid1 = l + (r-l)/3;
    int mid2 = r - (r-l)/3;
    mergesort(arr , l , mid1);//call 1
    mergesort(arr , mid1+1 , mid2); // call 2
    mergesort(arr , mid2+1 , r); // call 3
    merge(arr , l , r , mid1 , mid2);
}
void display(int arr[] , int n){
    for(int i = 0 ; i < n ; i++) cout << arr[i] << " ";
    cout << endl;
}
int main(){
    srand(time(0));
    ofstream out;
    out.open("threeway.txt");
    for(int i = 1 ; i <= 1000 ; i++){
        int arr[i];
        for(int j = 0 ; j < i ; j++){
            arr[j] = rand()%100;
        }
        mergesort(arr , 0 , i-1);
        // display(arr , i);
        out << i << " " << steps << "\n";
        steps = 0;
    }
    return 0;
}