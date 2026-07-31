class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int> mpp;
        int ans = 0;
        int n = word.size();
        for (int i = 0;i<n;i++){
            mpp[word[i]]++;
        }
        vector<pair<int,char>> vec;
        for (auto it : mpp){
            int f = it.second;
            char c = it.first;
            vec.push_back({f,c});
        }
        sort(vec.rbegin(),vec.rend());
        int i = 0;
        int j = 0;
        int k = 0;
        int m = 0;
        int uniqueLen = vec.size();

        if(uniqueLen >= 1){
            i = 8;
        }
        if(uniqueLen >= 9){
            j = 8;
        }
        if(uniqueLen >= 17){
            k = 8;
        }
        if(uniqueLen >= 25){
            m = 2;
        }
        int iterator = 0;
        while(i>0 && iterator < vec.size()){
            int f = vec[iterator].first;
            ans += f;
            i--;
            iterator++;
        }
        while(j>0 && iterator < vec.size()){
            int f = vec[iterator].first;
            ans += 2*f;
            j--;
            iterator++;
        }
        while(k>0 && iterator < vec.size()){
            int f = vec[iterator].first;
            ans += 3*f;
            k--;
            iterator++;
        }
        while(m>0 && iterator < vec.size()){
            int f = vec[iterator].first;
            ans += 4*f;
            m--;
            iterator++;
        }

        return ans;
    }
};