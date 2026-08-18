class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int maxEl = *max_element(nums.begin(),nums.end());
        vector<int> ranks(maxEl+1,0);
        vector<int> canBeAns(maxEl+1,0);
        for (int i = 0;i<nums.size();i++){
            canBeAns[nums[i]] = 1;
        }
        int n = nums.size();
        int rank = 1;
        for (int i = 0;i<n;i++){
            for(int j = 0;j<k;j++){
                if(i+k-1<n){
                    if(ranks[nums[i+j]] == rank){
                        continue;
                    }
                    else if(ranks[nums[i+j]] == 0){
                        ranks[nums[i+j]] = rank;
                    }
                    else{
                        canBeAns[nums[i+j]] = 0;
                        ranks[nums[i+j]] == rank;

                    }
                }
            }
            rank++;
        }
        for (int i = maxEl;i>=0;i--){
            if(canBeAns[i] == 1){
                return i;
            }
        }
        return -1;
    }
};