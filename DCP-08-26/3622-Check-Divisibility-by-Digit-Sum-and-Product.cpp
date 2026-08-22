class Solution {
public:
    int solve(int n){
        int sum = 0;
        int prod  = 1;

        while(n>0){
            int dig = n%10;
            sum+=dig;
            prod*=dig;
            n/=10;
        }

        return sum + prod;
    }
    bool checkDivisibility(int n) {
        int factor = solve(n);

        return n%factor==0;
    }
};