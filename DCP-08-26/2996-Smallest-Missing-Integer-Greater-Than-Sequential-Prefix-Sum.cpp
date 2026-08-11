class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int last = *max_element(nums.begin(),nums.end());
        vector<int> vis(last+1,0);
        int sum = nums[0];
        int ans = nums[0];
        vis[nums[0]] = 1;
        for (int i = 0;i<n;i++) vis[nums[i]] = 1;
        for(int i = 1;i<n;i++){
            
            if(nums[i] == nums[i-1] + 1){
                sum+=nums[i];
            }
            else{
                break;
            }
            ans = max(ans,sum);
        }
        if(ans > last) return ans;
        if(ans == last) return ans + 1;
        for (int i = ans;i<=last;i++){
            if(vis[i]!=1){
                return i;
            }
        }

        return last+1;
    }
};