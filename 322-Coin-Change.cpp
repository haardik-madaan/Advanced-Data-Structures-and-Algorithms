class Solution {
public:
    // int solve(int idx, int n, vector<int> &coins, int amount,vector<vector<int>> &dp){
        
    //     if(amount == 0) return 0;

    //     if(idx >= n) return 1e7;

    //     if(amount < 0) return 1e7;
        
    //     if(dp[idx][amount]!=-1) return dp[idx][amount];


    //     int take = 1e7;
    //     int notTake = 1e7;

    //     if(amount >= coins[idx]) take = 1 + solve(idx,n,coins,amount-coins[idx],dp);
    //     notTake = solve(idx+1,n,coins,amount,dp);

    //     return dp[idx][amount] = min(take,notTake);
    // }
    int solve2(vector<int> &coins,int n, int amount, vector<vector<int>> &dp){

        for (int i = 0;i<n;i++){
            dp[i][0] = 0;
        }

        for (int i = 0;i<=amount;i++){
            if(i % coins[0] == 0){
                dp[0][i] = i / coins[0];
            }
        }


        for (int i = 1;i<n;i++){
            for (int j = 1;j<=amount;j++){
                if(j-coins[i] >= 0) dp[i][j] = min(dp[i-1][j],1 + dp[i][j-coins[i]]);
                else dp[i][j] = dp[i-1][j];
            }
        }

        return dp[n-1][amount];
    }


    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int> (amount+1,1e7));

        // int ans = solve(0,n,coins,amount,dp);
        int ans2 = solve2(coins,n,amount,dp);

        return ans2 >= 1e7 ? -1 : ans2;
    }
};