class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, unordered_set<int>> mpp;
        int n = nums.size();
        int rank = 1;
        for (int i = 0;i<n;i++){
            for(int j = 0;j<k;j++){
                if(i+k-1<n){
                    mpp[nums[i+j]].insert(rank);
                }
            }
            rank++;
        }
        int element = -1;
        for (auto it : mpp){
            int el = it.first;
            if(mpp[el].size() == 1){
                element = max(element,el);
            }
        }
        return element;
    }
};