class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int> mpp;
        vector<int> ans;
        int rank = 1;
        int n = arr.size();
        vector<int> arr2 = arr;
        sort(arr2.begin(),arr2.end());
        for(int i = 0;i<n;i++){
            if(!mpp.count(arr2[i])){
                mpp[arr2[i]] = rank;
                rank++;
            }
            
        }

        for (int i = 0;i<arr.size();i++){
            ans.push_back(mpp[arr[i]]);
        }

        return ans;
        
    }
};