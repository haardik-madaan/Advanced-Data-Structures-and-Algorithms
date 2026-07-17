class Solution {
public:
    int solve(int idx, int n, vector<int> &coins, int amount,vector<vector<int>> &dp){
        
        if(amount == 0) return 0;

        if(idx >= n) return 1e7;

        if(amount < 0) return 1e7;
        
        if(dp[idx][amount]!=-1) return dp[idx][amount];


        int take = 1e7;
        int notTake = 1e7;

        if(amount >= coins[idx]) take = 1 + solve(idx,n,coins,amount-coins[idx],dp);
        notTake = solve(idx+1,n,coins,amount,dp);

        return dp[idx][amount] = min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int> (amount+1,-1));

        int ans = solve(0,n,coins,amount,dp);

        return ans >= 1e7 ? -1 : ans;
    }
};