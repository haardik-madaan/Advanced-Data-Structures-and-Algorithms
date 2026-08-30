class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        int mini = *min_element(nums.begin(),nums.end());

        int miniI = -1;
        int maxiI = -1;
        
        int n = nums.size();

        for (int i = 0;i<n;i++){
            if(nums[i] == maxi){
                maxiI = i;
            }
            else if(nums[i] == mini){
                miniI = i;
            }


            if(maxiI != -1 && miniI!=-1){
                break;
            }
        }

        int startToMini = miniI+1;
        int startToMax = maxiI+1;

        int endToMini = n-miniI;
        int endToMaxi = n-maxiI;

        int donoStart = max(startToMini,startToMax);
        int donoEnd = max(endToMini,endToMaxi);
        int miniStartmaxiEnd = startToMini+endToMaxi;
        int maxiStartminiEnd = startToMax+endToMini;

        return min(donoStart,min(donoEnd,min(miniStartmaxiEnd,maxiStartminiEnd)));
    }
};