class Solution {
public:
    bool populate(int s, int e, int c1, int c2, vector<int> &nums, bool turnFirst){

        if(s>e){
            return c1 >= c2;
        }

        if(turnFirst){
            return populate(s+1,e,c1 + nums[s],c2,nums,!turnFirst) || populate(s,e-1,c1 + nums[e],c2,nums,!turnFirst);
        }
        else{
            return populate(s + 1, e, c1, c2 + nums[s],nums,!turnFirst) &&
            populate(s , e-1 ,c1,c2+nums[e],nums,!turnFirst);
        }

        return false;

    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        return populate(0,n-1,0,0,nums,true);        
    }
};