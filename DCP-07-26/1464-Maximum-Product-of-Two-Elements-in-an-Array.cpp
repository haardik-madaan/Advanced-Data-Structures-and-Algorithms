class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int first = 1;
        int second = 1;

        for(auto it : nums){
            if(it > first){
                second = first;
                first = it;
            }
            else if(it > second){
                second = it;
            }
        }

        return (first - 1)*(second -1);
    }
};