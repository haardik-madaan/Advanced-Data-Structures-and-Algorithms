class SGTree{
    public:
    vector<int> seg;

    SGTree(int n){
        seg.resize(4*n);
    }

    void buildTree(int index, int low, int high, vector<int> &arr){
        if(low == high) {
            seg[index] = arr[low];
            return;
        }

        int mid = (low+high)/2;

        buildTree(2*index+1,low,mid,arr);
        buildTree(2*index+2,mid+1,high,arr);

        seg[index] = max(seg[2*index+1],seg[2*index+2]);
    }

    int findMax(int index, int l, int r, int low, int high, vector<int> &arr){
        if(r<low || high < l) return INT_MIN;
        
        if(l<=low && high<=r) return seg[index];

        int mid = (low+high)/2;

        int left = findMax(2*index+1, l,r,low,mid,arr);
        int right = findMax(2*index+2,l,r,mid+1,high,arr);

        return max(left,right);
    }
};

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int sz = queries.size();
        vector<int> ans;
        int n = heights.size();
        SGTree* s1 = new SGTree(n);

        s1->buildTree(0,0,n-1,heights);

        for (int i = 0;i<sz;i++){
            int u = min(queries[i][0],queries[i][1]);
            int v = max(queries[i][0],queries[i][1]);

            int maxVal = max(heights[u],heights[v]);

            if(u==v){
                ans.push_back(u);
                continue;
            }
            if(heights[u] < heights[v]) {
                ans.push_back(v);
                continue;
            }
            else{
                int s = v + 1;
                int e = n - 1;
               
                int possibleAns = -1;
            while(s<=e){
                int mid = s + (e-s)/2;
                if(s1->findMax(0,s,mid,0,n-1,heights) > maxVal){
                    possibleAns = mid;
                    e = mid-1;
                }
                else{
                    s = mid+1;
                }
            }
                 ans.push_back(possibleAns);
            }
        }
        return ans;
    }
};