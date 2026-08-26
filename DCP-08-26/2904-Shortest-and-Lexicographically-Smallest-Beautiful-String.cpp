class Solution {
public:
    int findLen(string s, int k){

        int l = 0;
        int r = 0;
        int ans = INT_MAX;
        int n = s.size();
        int count = 0;
        while(r<n){
            if(s[r] == '1'){
                count++;
            }

            while(count > k){
                if(s[l] == '1'){
                    count--;
                }
                l++;
            }

             if (count == k) {
            while (s[l] == '0') {
                l++;
            }

            ans = min(ans, r - l + 1);
        }



            r++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        vector<string> subs;

        int len = findLen(s,k);

        for (int i = 0;i+len<=n;i++){
            string str = "";
            for (int j = i;j<i+len;j++){
                str.push_back(s[j]);
            }
            subs.push_back(str);
        }

        sort(subs.begin(),subs.end());

        for(int i = 0;i<subs.size();i++){
            int c = 0;
            for (int j = 0;j<subs[i].size();j++){
                if(subs[i][j] == '1'){
                    c++;
                }
            }
            if(c == k){
                return subs[i];
            }
        }

        return "";
    }
};