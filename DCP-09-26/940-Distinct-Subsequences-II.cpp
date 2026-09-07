class Solution {
public:
    int mod = 1e9+7;
    int distinctSubseqII(string s) {
        int n = s.size();

        vector<int> indexes(26,-1);
        vector<long long> dp(n,0);
        dp[0] = 2;
        indexes[s[0] - 'a'] = 0;

        for (int i = 1;i<n;i++){
            if(indexes[s[i] - 'a'] == -1){
                dp[i] = (2*dp[i-1])%mod;
            }
            else{
                int lastIndex = indexes[s[i] - 'a'];
                if(lastIndex - 1 >= 0) dp[i] = ((2*dp[i-1])%mod - dp[lastIndex-1])%mod;
                else dp[i] = (2*dp[i-1] - 1 + mod)%mod;
            }
            indexes[s[i] - 'a'] = i;
        }

        return (dp[n-1] - 1 + mod) % mod;
    }
};