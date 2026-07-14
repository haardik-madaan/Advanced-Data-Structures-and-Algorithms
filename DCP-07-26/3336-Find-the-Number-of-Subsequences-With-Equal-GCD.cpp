class Solution {
public:
int mod = 1e9+7;
    int solve(int index, vector<int> &nums, int gcd1, int gcd2 , int n, vector<vector<vector<int>>> &dp){
        

        if (index == n) {
            return (gcd1 != 0 && gcd2 != 0 && gcd1 == gcd2);
        }
        if(dp[index][gcd1][gcd2]!=-1) return dp[index][gcd1][gcd2];
        int skip = solve(index+1,nums,gcd1,gcd2,n,dp);
        int takeInSeq1 = solve(index+1,nums,gcd(gcd1,nums[index]),gcd2,n,dp);
        int takeInSeq2 = solve(index+1,nums,gcd1,gcd(gcd2,nums[index]),n,dp);

        return dp[index][gcd1][gcd2] = ((skip + takeInSeq1)%mod + takeInSeq2)%mod;

    }
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int x = *max_element(nums.begin(),nums.end());
        int gcd1 = 0;
        int gcd2 = 0;
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (x+1, vector<int> (x+1,-1)));
        return solve(0,nums,gcd1,gcd2,n,dp);
    }
};