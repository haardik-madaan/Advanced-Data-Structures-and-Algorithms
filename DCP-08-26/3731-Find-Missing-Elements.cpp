class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        int s = *min_element(nums.begin(),nums.end());
        int e = *max_element(nums.begin(),nums.end());
        int l = e-s+1;
        vector<int> freq(l+1,0);

        for (int i = 0;i<nums.size();i++){
            freq[nums[i] - s]++;
        }
        vector<int> ans;
        for (int i = 0;i<l;i++){
            if(freq[i] == 0){
                ans.push_back(s+i);
            }
        }

        return ans;
        
    }
};