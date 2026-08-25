class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<bool> vis(101,0);

        int n = nums.size();

        for(int i = 0;i<n;i++){
            vis[nums[i]] = 1;
        }
        long long multiple = k;
        while(multiple <= 100 && vis[multiple] == 1){
            multiple+=k;
        }
        return multiple;
    }
};