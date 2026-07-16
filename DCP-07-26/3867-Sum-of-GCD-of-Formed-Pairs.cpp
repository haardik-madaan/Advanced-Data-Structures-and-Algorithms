class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefGCD;

        int maxi = 0;

        for (int i = 0;i<n;i++){
            maxi = max(maxi,nums[i]);
            prefGCD.push_back(gcd(nums[i],maxi));
        }

        sort(prefGCD.begin(),prefGCD.end());

        for(auto it : prefGCD){
            cout<<it<<" ";
        }
        cout<<endl;

        long long sum = 0;
        int s = 0;
        int e = n-1;

        for (int i = 0;i<n/2;i++){
            sum += gcd(prefGCD[s],prefGCD[e]);
            s++; e--;
        }
        return sum;
    }
};