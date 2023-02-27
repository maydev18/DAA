void printOptimal(vector<vector<int>>& dp){
            int i = dp.size()-1;
            int j = dp[0].size()-1;
            while(i != 0 && j!=0){
                if(j < weight[i]) i--;
                else{
                    if(value[i] + dp[i-1][j-weight[i]] > dp[i-1][j]){
                        cout << i << " ";
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