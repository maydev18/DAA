/*Following code finds the maximum number of jobs(0 weight) to be scheduled by following a greedy strategy.
Overall TC- O(n*logn) and space - O(1)*/

#include<bits/stdc++.h>
using namespace std;
//Interval class containing all the details of a job
class Interval{
    public:
    int job , start_time , end_time;
    Interval(){
        job = start_time = end_time = 0;
    }
    Interval(int job , int start_time ,int end_time){
        this->job = job;
        this->start_time = start_time;
        this->end_time = end_time;
    }
};
class IntervalScheduling{
    public:
    Interval * jobs; //jobs array
    int size; // total jobs
    //O(n)
    void get_jobs(){
        //reading the value from the file
        ifstream in;
        in.open("input.txt");
        in >> size;
        jobs = new Interval[size+1];
        for(int i = 1 ; i <= size ; i++){
            int  start_time , end_time;
            in >> start_time >> end_time;
            jobs[i] = Interval(i,start_time , end_time);
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
        for(int i = 1 ; i <= size ; i++){
            cout << jobs[i].job << " " << jobs[i].start_time << " " << jobs[i].end_time << " " << endl;
        }
    }
    //finding the optimal solution O(n)
    void optimal_solution(){ 
        int currjobs = 1;
        int currtime = jobs[1].end_time;
        cout << "The jobs to be scheduled are: " << endl;
        cout << jobs[1].start_time << " " << jobs[1].end_time << endl;
        for(int i = 2 ; i <= size ; i++){
            if(jobs[i].start_time >= currtime){
                currjobs++;
                currtime = jobs[i].end_time;
                cout << jobs[i].start_time << " " << jobs[i].end_time << endl;
            }
        }
        cout << "The total number of jobs to be scheduled is : " << currjobs << endl;
    }
};
int main(){
    IntervalScheduling w;
    //getting the jobs from the input file
    w.get_jobs();
    //Sorting the jobs using quick sort according to the ending time
    w.sort(1 , w.size);
    // w.display();
    //Finding the optimal solution using greedy algorithm
    w.optimal_solution();
    return 0;
}