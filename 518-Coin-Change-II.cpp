class Solution {
public:
    int solve(int idx, vector<int> &coins, int amount, int n, vector<vector<int>> &dp){

        if(amount == 0){
            return 1;
        }

        if(idx >= n){
            return 0;
        }

        if(amount < 0){
            return 0;
        }

        if(dp[idx][amount]!=-1) return dp[idx][amount];

        int take = 0;
        int notTake = 0;
        if(amount >= coins[idx]) take = solve(idx,coins,amount-coins[idx],n,dp);
        notTake = solve(idx+1,coins,amount,n,dp);


        return dp[idx][amount] = take + notTake;

    }


    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int> (amount+1,-1));
        int ans = solve(0,coins,amount,n,dp);

        return ans;


    }
};