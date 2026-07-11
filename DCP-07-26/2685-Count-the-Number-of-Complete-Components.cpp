class Solution {
public:
    int dfs(int node, vector<vector<int>> &adj, vector<int> &vis,int &edgesss){
        if(vis[node] == 1){
            return 0;
        }

        vis[node] = 1;
        edgesss += adj[node].size();
        int cnt = 1;
        for (auto it : adj[node]){
            cnt+=dfs(it,adj,vis,edgesss);
        }

        return cnt;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int sz = edges.size();
        vector<pair<int,int>> ms;
        vector<vector<int>> adj(n);
        for (int i = 0;i<sz;i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n,0);
       
        for (int i = 0;i<n;i++){
            int edgesss = 0;
            if(!vis[i]){
                int nodes = dfs(i,adj,vis,edgesss);
                int e = edgesss;
                ms.push_back({nodes,edgesss/2});
            }
        }
        int count = 0;
        for (int i = 0;i<ms.size();i++){
            int nodes = ms[i].first;
            int edgess = ms[i].second;

            if(edgess == (nodes)*(nodes-1)/2){
                count++;
            }
        }

        return count;

    }
};