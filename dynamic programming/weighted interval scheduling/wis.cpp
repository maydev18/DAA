/* We are given n jobs , their start time , their end time and the prize of all jobs. We need to schedule the jobs in such a way such that no two jobs overlap and the prize we get after doing them is maximized. You need to print the optimal solution as well as the optimal value after performing the optimal jobs.
Initially we figured out recursive approach for the same but later on seen overlapping sub-problems and hence we decided to go with dp.
Overall complexity is : O(n * logn)    +    O(n * logn)   +    O(n)     =     O(n*logn)
                        for sorting            for P[]         //dp
*/
#include<bits/stdc++.h>
using namespace std;
//Interval class containing all the details of a job
class Interval{
    public:
    int job , start_time , end_time , profit;
    Interval(){
        job = start_time = end_time = profit = 0;
    }
    Interval(int job , int start_time ,int end_time ,int profit){
        this->job = job;
        this->start_time = start_time;
        this->end_time = end_time;
        this->profit = profit;
    }
};
class WIS{
    public:
    Interval * jobs; //jobs array
    int * p; //P array
    int size; // total jobs
    //O(n)
    void get_jobs(){
        //reading the value from the file
        ifstream in;
        in.open("input.txt");
        in >> size;
        jobs = new Interval[size+1];
        p = new int[size+1];
        for(int i = 1 ; i <= size ; i++){
            int  start_time , end_time , profit;
            in >> start_time >> end_time >> profit;
            jobs[i] = Interval(i,start_time , end_time , profit);
        }
    }
    //Partition function for quicksort O(n)
    int partition(int l , int r){
        int x = jobs[r].end_time;
        int i = l-1;
        for(int j = l ; j <= r-1 ; j++){
            if(jobs[j].end_time < x){
                Interval temp = jobs[i+1];
                jobs[i+1] = jobs[j];
                jobs[j] = temp;
                i++; 
            }
        }
        Interval temp = jobs[r];
        jobs[r] = jobs[i+1];
        jobs[i+1] = temp;
        return i+1;
    }
    //quick sort O(n * logn)
    void sort(int l , int r){
        if(l > r) return;
        int m = partition(l , r);
        sort(l , m-1);
        sort(m+1 , r);
    }
    //Displaying the jobs O(n)
    void display(){
        for(int i = 0 ; i < size ; i++){
            cout << jobs[i].job << " " << jobs[i].start_time << " " << jobs[i].end_time << " " << jobs[i].profit << endl;
        }
    }
    int binarysearch(int high , int starttime){
        int low = 1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(jobs[mid].end_time <= starttime){
                if(jobs[mid+1].end_time <= starttime){
                    low = mid+1;
                }
                else{
                    return mid;
                }
            }
            else{
                high = mid - 1;
            }
        }
        return 0;
    }
    //Making the P array O(n * logn)
    void makep(){
        for(int i = 1 ; i <= size ; i++) p[i] = 0;
        for(int i = size ; i >= 1 ; i--){
            p[i] = binarysearch(i-1 , jobs[i].start_time);
        }
        p[0] = 0;
        for(int i =0 ; i <= size ; i++) cout << p[i] << " ";
        cout << endl;
    }
    //Recursive O(2^n)
    int optimal_solution(int index){
        if(index == 0) return 0;
        int take = jobs[index].profit + optimal_solution(p[index]);
        int nottake = optimal_solution(index-1);
        return max(take , nottake);
    }
    //Tabulated time -> O(n) + space0 -> O(n)
    void optimal_solution(){ 
        vector<int> dp(size+1 , 0);
        for(int i = 1 ; i <= size ; i++){
            dp[i] = max(dp[i-1] , dp[p[i]] + jobs[i].profit);
        }
        for(int i = 1 ; i <= size ; i++) cout << dp[i] << " ";
        cout << endl;
        cout << "The optimal jobs to be done are: ";
        print_optimal_solution(dp , size);
        cout << endl << endl << "The optimal value is : " << dp[size] << endl;
    }
    //O(n)
    void print_optimal_solution(vector<int> & dp ,int index){
        if(index == 0) return;
        if(dp[p[index]]+jobs[index].profit > dp[index-1]){
            cout << jobs[index].job << " ";
            print_optimal_solution(dp , p[index]);
        }
        else print_optimal_solution(dp , index-1);
    }
    
};
int main(){
    WIS w;
    //getting the jobs from the input file
    w.get_jobs();
    //Sorting the jobs using quick sort according to the ending time
    w.sort(1 , w.size);
    //Making the P[] array where P[i] tells the last compatible job for ith index and if p[i] = 0 it means no job is compatible before i.
    w.makep(); 
    //Finding the optimal solution using Dynamic programming
    w.optimal_solution();
    return 0;
}