class DSU{
    public:
    vector<int> parent;
    vector<int> sizes;

    DSU(int n){
        parent.resize(n);
        sizes.resize(n);

        for (int i = 0;i<n;i++){
            parent[i] = i;
        }

        for (int i = 0;i<n;i++){
            sizes[i] = 1;
        }

    }

    int findParent(int node){
        if(node == parent[node]) return node;

       return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int a, int b){

        int pa = findParent(a);
        int pb = findParent(b);

        if(pa == pb) return;

        if(sizes[pa] > sizes[pb]){
            parent[pb] = pa;
            sizes[pa]+=sizes[pb];
        }
        else{
            parent[pa] = pb;
            sizes[pb]+=sizes[pa];
        }
    }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int len = nums.size();

        unordered_map<int,vector<int>> adj;
        DSU* dsu = new DSU(len);


        for (int i = 0; i + 1 < len; i++) {
            if (nums[i + 1] - nums[i] <= maxDiff) {
                dsu->unionBySize(i, i + 1);
            }
        }

        // for (auto it : adj){
        //     int node = it.first;
        //     vector<int> nextNodes = it.second;
        //     for (int i = 0;i<nextNodes.size();i++){
        //         dsu->unionBySize(node,nextNodes[i]);
        //     }
        // }

        int sz = queries.size();
        vector<bool> ans;

        for (int i = 0;i<queries.size();i++){
            int u = queries[i][0];
            int v = queries[i][1];

            int pu = dsu->findParent(u);
            int pv = dsu->findParent(v);

            if(pu == pv){
                ans.push_back(1);
            }
            else{
                ans.push_back(0);
            }

        }

        return ans;
    }
};