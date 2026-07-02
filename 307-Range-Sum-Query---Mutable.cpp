class SGTree{
    public:
    vector<int> seg;

    void buildTree(int index, int low, int high, vector<int> &arr){
        if(low == high){
            seg[index] = arr[low];
            return;
        }

        int mid = (low+high)/2;

        buildTree(2*index+1,low,mid,arr);
        buildTree(2*index+2,mid+1,high,arr);

        seg[index] = seg[2*index+1] + seg[2*index+2]; 
    }

    void update(int index, int low, int high, int i, int val, vector<int> &arr){
        if(low == high){
            seg[index] = val;
            return;
        }
        int mid = (low+high)/2;
        if(i<=mid){
            update(2*index+1,low,mid,i,val,arr);
        }
        else{
            update(2*index+2,mid+1,high,i,val,arr);
        }

        seg[index] = seg[2*index+1] + seg[2*index+2];
    }

    int findSum(int index, int l, int r, int low, int high, vector<int> &arr){
        if( r < low || high < l){
            return 0;
        }
        else if(low>=l && r>=high){
            return seg[index];
        }

        int mid = (low+high)/2;
        int left = findSum(2*index+1, l, r, low, mid, arr);
        int right = findSum(2*index+2,l,r,mid+1,high,arr);

        return left + right;
    }
};

class NumArray {
public:
vector<int> arr;
int n;
SGTree st;
    NumArray(vector<int>& nums) {
        arr = nums;
        n = nums.size();
        st.seg.resize(4*n);
        st.buildTree(0,0,n-1,arr);
    }
    
    void update(int index, int val) {
        st.update(0,0,n-1,index,val,arr);
    }
    
    int sumRange(int left, int right) {
        return st.findSum(0,left,right,0,n-1,arr);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */