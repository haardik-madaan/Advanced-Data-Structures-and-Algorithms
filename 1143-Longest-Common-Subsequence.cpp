class Solution {
public:
    // int solve(int i1, int i2, int n1, int n2, string &text1, string &text2,vector<vector<int>> &dp){

    //     if(i1 >= n1 || i2 >= n2) return 0;  
    //     if(dp[i1][i2] != -1) return dp[i1][i2];
    //     if(text1[i1] == text2[i2]){
    //         return dp[i1][i2] = 1 + solve(i1+1,i2+1,n1,n2,text1,text2,dp);
    //     }
    //     else{
    //         return dp[i1][i2] = max(solve(i1+1,i2,n1,n2,text1,text2,dp),solve(i1,i2+1,n1,n2,text1,text2,dp));
    //     }
    // }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();

        vector<vector<int>> dp(n1+1, vector<int> (n2+1,0));
        // return solve(0,0,n1,n2,text1,text2,dp);
        return solve2(dp,text1,text2,n1,n2);
    }

    int solve2(vector<vector<int>> &dp, string &text1, string& text2, int n1, int n2){

        
        for (int i = n1-1;i>=0;i--){
            for (int j = n2-1;j>=0;j--){

                if(text1[i] == text2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else{
                    dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
                } 
            }
        }

        return dp[0][0];
    }
};