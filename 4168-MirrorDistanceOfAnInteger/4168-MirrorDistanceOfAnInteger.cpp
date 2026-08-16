// Last updated: 8/16/2026, 6:49:20 PM
class Solution {
public:
    int mirrorDistance(int n) {
        return abs(n-reverse(n));
    }
    int reverse(int n){
        int rev=0;
        while(n>0){
            int digit=n%10;
            rev=rev*10+digit;
            n/=10;
        }
        return rev;
    }
};