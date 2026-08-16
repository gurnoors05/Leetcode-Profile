// Last updated: 8/16/2026, 6:58:44 PM
class Solution {
public:
    int concatenatedBinary(int n) {
        // int M=1e9+7;
        // long ans=0;
        // for(int i=1;i<=n;i++){
        //     int digitsToCome=log2(i)+1;
        //     ans=(((ans<<digitsToCome)%M)+i)%M;
        // }
        // return ans;

        // 2nd way using  method to find digits in current number
        int M=1e9+7;
        long ans=0;
        int digits=0;
        for(int i=1;i<=n;i++){
            if((i & (i-1))==0){
                digits++;
            }
            ans=((ans<<digits)%M+i)%M;;
        }
        return ans;
    }
};