#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
class MCM{
    public:
        int n;
        int * arr;
        void takeInput(){
            ifstream in("input.txt");
            in >> n;
            arr = new int[n];
            for(int i = 0 ; i < n ; i++){
                in >> arr[i];
            }
        }
        //Recursive code - exponential
        int optimalValue(int i , int j){
            if(i == j){
                return 0;
            }
            int ans = 1000000009;
            for(int k = i ; k < j ; k++){
                ans = min(ans , arr[i-1]*arr[k]*arr[j] + optimalValue(i , k)+ optimalValue(k+1,j));
            }
            return ans;
        }
        //DP code - O(n^3)
        int optimalValue(){
            vector<vector<int>> dp(n , vector<int>(n , 0));
            vector<vector<int>> s(n , vector<int>(n , 0));
            for(int i = n-2 ; i >= 1 ; i--){
                for(int j = i+1 ; j <= n-1 ; j++){
                    dp[i][j] = 1000000009;
                    for(int k = i ; k < j ; k++){
                        int cost = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                        if(dp[i][j] >= cost){
                            dp[i][j] = cost;
                            s[i][j] = k;
                        }
                    }
                }
            }
            cout << "printing the dp table" << endl;
            for(int i = 1 ; i < n ; i++){
                for(int j = 1 ; j < n ; j++){
                    cout << dp[i][j] << " ";
                }
                cout << endl;
            }
            cout << "printing the partition table" << endl;
            for(int i = 1 ; i < n ; i++){
                for(int j = 1  ; j < n ; j++){
                    cout << s[i][j] << " ";
                }
                cout << endl;
            }
            cout << "The optimal solution is : ";
            printOptimal(s , 1 , n-1);
            cout << endl;
            cout << "The optimal value is: ";
            return dp[1][n-1];
        }
        void printOptimal(vector<vector<int>> & s , int i , int j){
            if(i == j){
                cout << "A"+to_string(i);
                return;
            }
            cout << "(";
            printOptimal(s , i , s[i][j]);
            printOptimal(s , s[i][j]+1 , j);
            cout << ")";
        }
};
int main(){ 
    MCM m;
    m.takeInput();
    // cout << m.optimalValue(1 , m.n-1);
    cout << m.optimalValue();
    return 0;
}
