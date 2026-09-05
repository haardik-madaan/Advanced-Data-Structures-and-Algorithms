class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> maxes;
        vector<int> minis;
        int n = nums.size();
        int maxi = 0;
        int mini = INT_MAX;
        for (int i = 0;i<n;i++){
            maxi = max(maxi,nums[i]);
            maxes.push_back(maxi);
            mini = min(mini,nums[n-i-1]);
            minis.push_back(mini);
        }
        reverse(minis.begin(),minis.end());
        for (int i = 0;i<n;i++){
            if(maxes[i] - minis[i] <= k){
                return i;
            }
        }
        return -1;
    }
};