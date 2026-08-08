class Solution {
public:
    void populateSuspicious(vector<bool> &suspicious, int k, vector<vector<int>> &invokes){

        suspicious[k] = 1;

        for (auto it : invokes[k]){
            if(!suspicious[it]){
                populateSuspicious(suspicious,it,invokes);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> invokedBy(n);
        vector<vector<int>> invokes(n);
        int sz = invocations.size();
        for(int i = 0;i<sz;i++){
            int a = invocations[i][0];
            int b = invocations[i][1];

            invokedBy[b].push_back(a);
            invokes[a].push_back(b);
        }
        vector<bool> suspicious(n,0);
        populateSuspicious(suspicious,k,invokes);
        bool canDelete = true;
        for (int i = 0;i<n;i++){
            if(suspicious[i] == 1){
                for (auto it : invokedBy[i]){
                    if(!suspicious[it]){
                        canDelete = false;
                    }
                }
            }
        }
        vector<int> ans;
        if(canDelete){
            for (int i = 0;i<n;i++){
                if(suspicious[i] == 1){
                    continue;
                }
                else{
                    ans.push_back(i);
                }
            }
        }
        else{
            for (int i = 0;i<n;i++){
                ans.push_back(i);
            }
        }
        return ans;
    }

};