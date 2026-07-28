class Solution {
public:
    string smallestPalindrome(string s) {
    
        string res = "";
        int n = s.size();
        vector<int> freq(26,0);
        string front = "";
        string back = "";
        string centerElement = "";
        for (int i = 0;i<n;i++){
            freq[s[i]-'a']++;
        }

        for (int i = 0;i<26;i++){
            if(freq[i] != 0){
                int cnt = freq[i];

                if(cnt == 1){
                    centerElement = 'a' + i;
                }

                else if(cnt % 2 != 0){
                    centerElement = 'a' + i;
                }

                front += string(cnt/2,'a' + i);
                back += string(cnt/2, 'a' + i);
            }
        }
        
        if(centerElement != ""){
            front += centerElement;
        }

        reverse(back.begin(),back.end());
        return front + back;
        
    }
};