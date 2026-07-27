class Solution {
public:
    int solve(int idx, int n, vector<int> &prices, int fee,bool has,vector<vector<int>> &dp){
        
        if(idx >= n) return 0;
        if(dp[idx][has] != -1) return dp[idx][has];
        int sell = INT_MIN;
        int buy = INT_MIN;
        if(has){
            sell = max((prices[idx] - fee) + solve(idx+1,n,prices,fee,false,dp),solve(idx+1,n,prices,fee,true,dp));
        }
        else{
            buy = max(-prices[idx] + solve(idx+1,n,prices,fee,true,dp), solve(idx+1,n,prices,fee,false,dp));
        }
        return dp[idx][has] = max(buy,sell);
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int> (2,-1));
        return solve(0,n,prices,fee,0,dp);
    }
};