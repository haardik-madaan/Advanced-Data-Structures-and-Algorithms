class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
            [](const vector<int>& a, const vector<int>& b) {
                if (a[0] == b[0])
                    return a[1] > b[1];   
                return a[0] < b[0];       
            }
        );
        int n = intervals.size();
        int s = intervals[0][0];
        int e = intervals[0][1];
        int count = 0;
        for (int i = 1;i<n;i++){
            int u = intervals[i][0];
            int v = intervals[i][1];

            if(s<= u && e>=v){
            count++;
        }

        s = min(s,u);
        e = max(e,v);
    }   

    return n - count;

    }
};