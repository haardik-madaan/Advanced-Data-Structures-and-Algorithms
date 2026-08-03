class Solution {
public:
    int solve(int idx, int n, vector<int> &a, vector<int> &dp){

        if(idx >= n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int result = -1e9;

        result = max(result, a[idx] - solve(idx+1,n,a,dp));
        if(idx+1 < n) result = max(result, a[idx] + a[idx+1] - solve(idx+2,n,a,dp));
        if(idx+2 < n) result = max(result, a[idx] + a[idx+1] + a[idx+2] - solve(idx+3,n,a,dp));

        return dp[idx] = result;
    }
    string stoneGameIII(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n,-1);
        int res = solve(0,n,a,dp);

        if(res > 0) return "Alice";
        else if(res < 0) return "Bob";
        else return "Tie";
        
    }
};