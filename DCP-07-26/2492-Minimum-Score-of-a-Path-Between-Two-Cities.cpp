class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int sz = roads.size();

        unordered_map<int, vector<vector<int>>> mpp;

        for (int i = 0;i<sz;i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];

            mpp[u].push_back({v,w});
            mpp[v].push_back({u,w});

        }

        queue<int> q;
        vector<bool> vis(n + 1, false);

        q.push(1);
        vis[1] = true;

        int ans = INT_MAX;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto &e : mpp[u]) {
                int v = e[0];
                int w = e[1];

                ans = min(ans, w);

                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        return ans;
    }
};