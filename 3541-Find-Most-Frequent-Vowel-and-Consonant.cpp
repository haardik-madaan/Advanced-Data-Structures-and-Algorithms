class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> v;
        unordered_map<char,int> c;
        int vf = 0;
        int cf = 0;
        int n = s.size();
        for (int i = 0;i<n;i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                v[s[i]]++;
                vf = max(vf,v[s[i]]);
            }
            else{
                c[s[i]]++;
                cf = max(cf,c[s[i]]);
            }
        }

        return vf+cf;
    }
};