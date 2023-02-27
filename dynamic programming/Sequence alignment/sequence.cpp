#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
class SequenceAlignment{
    public:
        string p , q;
        int costMismatch , costGap;
        void getInput(){
            ifstream in;
            in.open("input.txt");
            in >> costMismatch >> costGap;
            in >> p >> q;
        }
        //Recursive Code O(3^n)
        int optimalValue(int i , int j){
            if(i < 0 && j < 0){
                return 0;
            }
            if(i < 0){
                return (j+1)*costGap;
            }
            if(j < 0){
                return (i+1)*costGap;
            }
            if(p[i] == q[j]){
                return optimalValue(i-1 , j-1);
            }
            else{
                return min(costMismatch + optimalValue(i-1 , j-1) ,min(costGap + optimalValue(i , j-1) ,costGap+ optimalValue(i-1,j)));
            }
        }

        //DP approach O(n^2)

        int optimalValue(){
            vector<vector<int>> dp(p.size()+1 , vector<int>(q.size()+1 , 0));
            //initialization
            dp[0][0] = 0;
            for(int i = 1 ; i <= p.size() ; i++) dp[i][0] = i*costGap;
            for(int i = 1 ; i <= q.size() ; i++) dp[0][i] = i*costGap;
            //Iteration
            for(int i = 1 ; i <= p.size() ; i++){
                for(int j = 1 ; j <= q.size() ; j++){
                    if(p[i-1] == q[j-1]){
                        dp[i][j] = dp[i-1][j-1];
                    }
                    else{
                        dp[i][j] = min(costMismatch +dp[i-1][j-1] , min(costGap + dp[i][j-1] , costGap + dp[i-1][j]));
                    }
                }
            }
            for(int i = 0 ; i <= p.size() ; ++i){
                for(int j =0 ; j <= q.size() ; ++j){
                    cout << dp[i][j] << " ";
                }
                cout << endl;
            }
            printSequence(dp);
            return dp[p.size()][q.size()];
        }
        void printSequence(vector<vector<int>> & dp){
            string newp = "", newq = "";
            int i = p.size() , j = q.size();
            while(i > 0 && j > 0){
                if(p[i-1] == q[j-1]){
                    newp += p[i-1];
                    newq += q[j-1];
                    i--;
                    j--;
                }
                else{
                    if(costMismatch + dp[i-1][j-1] <= min(costGap + dp[i][j-1] , costGap + dp[i-1][j])){
                        newp += p[i-1];
                        newq += q[j-1];
                        i--;
                        j--;
                    }
                    else if(costGap + dp[i-1][j] <= min(costMismatch + dp[i-1][j-1] , costGap + dp[i][j-1])){
                        newp += p[i-1];
                        newq += " ";
                        i--;
                    }
                    else{
                        newp += " ";
                        newq += q[j-1];
                        j--;
                    }
                }
            }
            while(i > 0){
                newp += p[i-1];
                i--;
            }
            while(j > 0){
                newq += q[j-1];
                j--;
            }
            reverse(newp.begin() , newp.end());
            reverse(newq.begin() , newq.end());
            cout << newp << endl;
            cout << newq << endl;
        }
};
int main(){
    SequenceAlignment s;
    s.getInput();
    // cout << s.optimalValue(s.p.size()-1 , s.q.size()-1);
    cout << s.optimalValue();
    return 0;
}
