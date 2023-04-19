/*Longest Common subsequence. Time complexity = O(n^2) and space complexity is O(n^2)*/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
class LCS{
    public:
        string s1 , s2;
        void getInput(){
            ifstream in;
            in.open("input.txt");
            in >> s1 >> s2;
        }
        //Recursive code for LCS O(2^n)
        //space - O(logn)
        int optimalValue(int i , int j){
            if(i < 0 || j < 0){
                return 0;
            }
            if(s1[i] == s2[j]){
                return 1 + optimalValue(i-1,j-1);
            }
            else{
                return max(optimalValue(i-1,j) , optimalValue(i , j-1));
            }
        }
        //DP Optimization
        //  time - O(n^2) and space - O(n^2)
        int optimalValue(){
            vector<vector<int>> dp(s1.size()+1 , vector<int>(s2.size()+1 , 0));
            for(int i = 1 ; i <= s1.size() ; i++){
                for(int j = 1 ; j <= s2.size() ; j++){
                    if(s1[i-1] == s2[j-1]){
                        dp[i][j] = 1 + dp[i-1][j-1];
                    }
                    else{
                        dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                    }
                }
            }
            for(int i = 0 ; i <= s1.size() ; i++){
                for(int j = 0 ; j <= s2.size() ; j++){
                    cout << dp[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
            printOptimal(dp);
            return dp[s1.size()][s2.size()];
        }
        //backtracking the dp table. This is gonna print any one LCS, for printing all LCS use recursion.
        // space
        // time - O(max(n,m));
        //space - O(1)
        void printOptimal(vector<vector<int>> & dp){
            int i = s1.size() , j = s2.size();
            string ans = "";
            while(i > 0 && j > 0){
                if(s1[i-1] == s2[j-1]){
                    ans += s1[i-1];
                    i--;j--;
                }
                else{
                    if(dp[i-1][j] > dp[i][j-1]){
                        i--;
                    }
                    else{
                        j--;
                    }
                }
            }
            reverse(ans.begin() , ans.end());
            cout << "LCS is : " << ans << endl;
        }
};
int main(){
    LCS l;
    l.getInput();
    // cout << l.optimalValue(l.s1.size()-1,l.s2.size()-1);
    cout << l.optimalValue();
    return 0;
}