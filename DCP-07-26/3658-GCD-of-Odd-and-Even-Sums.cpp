class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        n *= 2; int osum = 0; int esum = 0;

        for (int i = 1;i<=n;i++){
            if(i%2==0) esum+=i;
            else osum+=i;
        }

        return gcd(osum,esum);
    }
};