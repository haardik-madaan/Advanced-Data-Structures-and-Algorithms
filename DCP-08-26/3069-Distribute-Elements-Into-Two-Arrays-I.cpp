class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2*n+1);
        
        ans[0] = nums[0];
        ans[n] = nums[1];
        int it = 2;

        int i = 0;
        int j = n;

        while(i<n && j<2*n && it < n){
            if(ans[i] > ans[j]){
                ans[i+1] = nums[it];
                i++;
            }
            else{
                ans[j+1] = nums[it];
                j++;
            }
            it++;
        }
        vector<int> res;
        for (int i = 0;i<ans.size();i++){
            if(ans[i]!=0) res.push_back(ans[i]);
        }
        return res;
    }
};