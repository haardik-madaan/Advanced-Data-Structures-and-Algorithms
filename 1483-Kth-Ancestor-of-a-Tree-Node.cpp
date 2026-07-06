class TreeAncestor {
public:
vector<vector<int>> ances;
int cols;
    int findLog(int n){
        int val = 1;

        while(pow(2,val) <= n){
            val++;
        }

        return val;
    }
    TreeAncestor(int n, vector<int>& parent) {
        int logn = findLog(n)+1;

        ances.resize(n, vector<int> (logn, -1));

        for(int i = 0;i<n;i++){
            ances[i][0] = parent[i];
        }

        for (int i = 1;i<logn;i++){
            for (int j = 1;j<n;j++){
                if(ances[j][i-1]!=-1)
                ances[j][i] = ances[ances[j][i-1]][i-1];
            }
        }

        cols = logn;
    }
    
    int getKthAncestor(int node, int k) {
        
        for (int i = 0;i<cols;i++){
            if(k & (1<<i)){
                node = ances[node][i];
                if(node == -1){
                    break;
                }
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */