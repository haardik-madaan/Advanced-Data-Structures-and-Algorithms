class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool allEven = true;
        bool allOdd = true;
        int minOdd = INT_MAX;
        int minEven = INT_MAX;

        int n = nums1.size();

        for (int i = 0;i<n;i++){
            if(nums1[i]%2 == 0){
                allOdd = false;
                minEven = min(minEven,nums1[i]);
            }
            else{
                allEven = false;
                minOdd = min(minOdd,nums1[i]);
            }
        }

        if(allEven || allOdd) return true;

        bool canBeEven = true;
        bool canBeOdd = true;
        
        for(int i = 0;i<n;i++){
            if(nums1[i]%2 == 0){
                if(nums1[i] - minOdd < 1){
                    canBeOdd = false;
                }
            }
        }

        for(int i = 0;i<n;i++){
            if(nums1[i]%2 == 1){
                if(nums1[i] - minOdd < 1){
                    canBeEven = false;
                }
            }
        }
        
        return canBeEven || canBeOdd;
    }
};