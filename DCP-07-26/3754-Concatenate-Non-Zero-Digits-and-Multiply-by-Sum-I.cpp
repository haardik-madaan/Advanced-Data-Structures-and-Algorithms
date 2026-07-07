class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum = 0;
        int x = 1;
        string str = "";
        while(n > 0){
            int digit = n % 10;
            n = n/10;
            sum+=digit;

            if(digit!=0)
            str+= to_string(digit);
        }

        reverse(str.begin(),str.end());

        if(str == "") return 0;

        long long ans = stoi(str);

        return ans * sum;
    }
};