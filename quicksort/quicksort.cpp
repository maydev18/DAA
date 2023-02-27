//this program is of quick sort.
//it is used to sort a given array using divide and conquer technique
//time complexity = O(n*logn)
//space = O(1)
#include <iostream>
#include <time.h>
#include <fstream>
#include <random>
using namespace std;
int steps = 0;
//following function complexity is O(n)
int random_partition(int arr[] , int l , int r){
    int random = l + (rand()%(r-l+1));
    int temp = arr[random];
    arr[random] = arr[r];
    arr[r] = temp;
    int x = arr[r];
    int i = l-1;
    for(int j = l ; j <= r-1 ; j++){
        steps++;
        if(arr[j] < x){
            temp = arr[i+1];
            arr[i+1] = arr[j];
            arr[j] = temp;
            i++;
        }
    }
    arr[r] = arr[i+1];
    arr[i+1] = x; 
    return i+1;
}
//following function complexity is O(n)
int partition(int arr[] , int l , int r){
    int x = arr[r];
    int i = l-1;
    for(int j = l ; j <= r-1 ; j++){
        steps++;
        if(arr[j] < x){
            int temp = arr[i+1];
            arr[i+1] = arr[j];
            arr[j] = temp;
            i++;
        }
    }
    arr[r] = arr[i+1];
    arr[i+1] = x; 
    return i+1;
}
//following function complexity is O(n*logn)
void quicksort(int arr[] , int l , int r , bool random){
    steps++;
    if(l >= r) return;
    int mid;
    if(random == 1){
        mid = partition(arr , l , r);
        quicksort(arr , l , mid-1 , 1);
        quicksort(arr , mid+1 , r , 1);
    }
    else{
        mid = random_partition(arr , l , r);
        quicksort(arr , l , mid-1 , 0);
        quicksort(arr , mid+1 , r , 0);
    }
}
void display(int arr[] , int n){
    for(int i = 0 ; i < n ; i++) cout << arr[i] << " ";
    cout << endl;
}
int main(){
    srand(time(0));
    ofstream out("graph.txt");
    for(int i = 1 ; i <= 1000 ; i++){
        int arr[i];
        for(int j = 0 ; j < i ; j++){
            arr[j] = rand()%100;
        }
        int random , last;
        quicksort(arr , 0 , i-1 , 1);
        random = steps;
        steps = 0;
        for(int j = 0 ; j < i ; j++){
            arr[j] = rand()%100;
        }
        quicksort(arr , 0 , i-1 , 0);
        last = steps;
        out << i << " " << last << " "<<random << "\n";
        steps = 0;
    }
}