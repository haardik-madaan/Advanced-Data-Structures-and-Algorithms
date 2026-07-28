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
        
        vector<int> prev(n2+1,0);
        
        for (int i = n1-1;i>=0;i--){
            vector<int> curr(n2+1,0);
            for (int j = n2-1;j>=0;j--){
                if(text1[i] == text2[j]){
                    curr[j] = 1 + prev[j+1];
                }
                else{
                    curr[j] = max(prev[j],curr[j+1]);
                } 
            }
            prev = curr;
        }
        return prev[0];
    }
};