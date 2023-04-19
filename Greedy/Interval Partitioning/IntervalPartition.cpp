/*The following codes finds out the minimum number of resources needed to run all jobs such that no two jobs overlap at a same time
Time complexity- O(n*logn)
space - O(1)
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
class IntervalPartitioning{
    public:
        int n;
        int * start_time;
        int * end_time;
        //taking the input and then sorting them . O(nlogn)
        void takeInput(){
            ifstream in("input.txt");
            in >> n;
            start_time = new int[n];
            end_time = new int[n];
            for(int i = 0 ; i < n ; i++) {
                in >> start_time[i] >> end_time[i];
            }
        }
        // finds the minimum resources using 2 pointers. O(nlogn)
        void findMinimum(){
            sort(start_time , start_time+n);
            sort(end_time , end_time+n);
            int rooms = 1;
            int maxrooms = 1;
            int i = 1 , j = 0;
            while(i < n && j < n){
                if(start_time[i] <= end_time[j]){
                    rooms++;
                    i++;
                }
                else{
                    j++;
                    rooms--;
                }
                maxrooms = max(maxrooms , rooms);
                
            }
            cout << "The minimum number of rooms required are : " << maxrooms << endl;
        }
        //Linear time algorithm
        void findMin(){
            int maxi = 0;
            for(int i = 0 ; i < n ; i++){
                maxi = max(maxi , end_time[i]);
            }
            vector<int> line(maxi+2 , 0);
            for(int i = 0 ; i < n ; i++){
                line[start_time[i]]++;
                line[end_time[i]+1]--;
            }
            int ans = 0;
            for(int i = 1 ; i < maxi+2 ; i++){
                line[i] += line[i-1];
                ans = max(line[i] , ans);
            }
            cout << "The minimum number of rooms required are : " << ans << endl;
        }
};
int main(){
    IntervalPartitioning i;
    i.takeInput();
    i.findMin();
    return 0;
}