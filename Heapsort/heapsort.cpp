//time complexity - O(n * logn)
#include <iostream>
#include <fstream>
using namespace std;
class Heapsort{
    public:
        int * arr;
        int n;
        int heap_size;
        void input(){
            ifstream in("file.txt");
            in >> n;
            arr = new int[n+1];
            for(int i = 1 ; i <= n ; i++){
                in >> arr[i];
            }
        }
        //O(n)
        void Build_heap(){
            heap_size = n;
            for(int i = n/2 ; i >= 1 ; i--){
                int curr = i , c1 = 2*i , c2 = 2*i + 1;
                while(1){
                    int maxi = curr;
                    if(c1 <= n && arr[c1] > arr[maxi]) maxi = c1;
                    if(c2 <= n && arr[c2] > arr[maxi]) maxi = c2;
                    if(maxi == curr){
                        break;
                    }
                    swap(arr[maxi] , arr[curr]);
                    curr = maxi;
                    c1 = maxi*2 , c2 = maxi*2+1;
                }
            }
        }
        void heapify(){
            int curr = 1 , c1 = 2 , c2 = 3;
            while(1){
                int maxi = curr;
                if(c1 <= heap_size && arr[c1] > arr[maxi]) maxi = c1;
                if(c2 <= heap_size && arr[c2] > arr[maxi]) maxi = c2;
                if(maxi == curr){
                    break;
                }
                swap(arr[maxi] , arr[curr]);
                curr = maxi;
                c1 = maxi*2 , c2 = maxi*2+1;
            }
        }
        void sort(){
            while(heap_size){
                swap(arr[1] , arr[heap_size]);
                heap_size--;
                heapify();
            }
            for(int i = 1 ; i <= n ; i++){
                cout << arr[i] << " ";
            }
        }
};
int main(){
    Heapsort h;
    h.input();
    h.Build_heap();
    h.sort();
}