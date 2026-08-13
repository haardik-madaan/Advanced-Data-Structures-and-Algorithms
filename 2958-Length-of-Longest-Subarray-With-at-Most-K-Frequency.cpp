class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        int len = 0;

        int l = 0;
        int r = 0;

        while(r<n){
            mpp[nums[r]]++;

            while(mpp[nums[r]] > k){
                mpp[nums[l]]--;
                l++;
            }

            len = max(len, r-l+1);
            r++;
        }

        return len;
    }
};