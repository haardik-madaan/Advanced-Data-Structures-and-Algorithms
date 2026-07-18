class Solution {
public:
    void solve(int idx, int n, vector<int> &candidates, int target, vector<int> &vec, vector<vector<int>> &finalVec){


        if(target == 0){
            finalVec.push_back(vec);
            return;
        }

        if(idx >= n) return;

        if(target < 0) return;

        if(target >= candidates[idx]){
            vec.push_back(candidates[idx]);
            solve(idx,n,candidates,target-candidates[idx],vec,finalVec);
            vec.pop_back();
        }
        solve(idx+1,n,candidates,target,vec,finalVec);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();

        vector<int> vec;
        vector<vector<int>> finalVec;

        solve(0,n,candidates,target,vec,finalVec);

        return finalVec;
    }
};