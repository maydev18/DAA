/* Subset sum - find the maximum weight you can put in the knapsack so that the value is maximized. We will be using dp to do so.
Time- O(n^2)
Space- O(n^2)
Optimized- */
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class SubsetSum{
    public:
        int * weight;
        int n;
        int W;
        void takeinput(){
            ifstream in;
            in.open("input.txt");
            in >> n >> W;
            weight = new int[n+1];
            for(int i = 0 ; i  < n; i++){
                in >> weight[i+1];
            }
            weight[0] = 0;
        }
        //Recursive code- O(2^n)
        int findOptimal(int index , int w){
            if(index == 0) return 0;
            int nottake = findOptimal(index-1 , w);
            int take = 0;
            if(weight[index] <= w) take = weight[index] + findOptimal(index-1 , w-weight[index]);
            return max(take , nottake);
        }
        //DP code
        int findOptimal(){
            vector<vector<int>> dp(n+1 , vector<int>(W+1 , 0));
            for(int i = 1 ; i <= n ; i++){
                for(int w = 1 ; w <= W ; w++){
                    int nottake = dp[i-1][w];
                    int take = 0;
                    if(weight[i] <= w) take = weight[i] + dp[i-1][w-weight[i]];
                    dp[i][w] = max(take , nottake);
                }
            }
            for(int i = 0 ; i <= n ; i++){
                for(int j = 0 ; j <= W ; j++){
                    cout << dp[i][j] << " ";
                }
                cout << endl;
            }
            printOptimal(dp);
            return dp[n][W];
        }
        void printOptimal(vector<vector<int>>& dp){
            int i = dp.size()-1;
            int j = dp[0].size()-1;
            while(i != 0 && j!=0){
                if(j < weight[i]) i--;
                else{
                    if(weight[i] + dp[i-1][j-weight[i]] > dp[i-1][j]){
                        cout << weight[i] << " ";
                        j -= weight[i];
                        i--;
                    }
                    else{
                        i--;
                    }
                }
            }
            cout << endl;
        }

};
int main(){
    SubsetSum s;
    s.takeinput();
    cout << s.findOptimal();
}