// Last updated: 8/16/2026, 6:51:44 PM
class Solution {
public:
    // int M=1e9+7;
    // int dp[201][201][2];
    // int numberOfStableArrays(int zero, int one, int limit) {
    //     memset(dp,-1,sizeof(dp));
    //     int startWithOne=solve(zero,one,limit,false);
    //     int startwithZero=solve(zero,one,limit,true);
    //     return (startWithOne + startwithZero)%M;
    // }
    // int solve(int zero,int one,int limit,bool wasOne){
    //     if(zero==0 && one==0){
    //         return 1;
    //     }
    //     if(dp[zero][one][wasOne]!=-1){
    //         return dp[zero][one][wasOne];
    //     }
    //     int result=0;
    //     if(wasOne){ // explore 0's
    //         for(int len=1;len<=min(limit,zero);len++){
    //             result=(result + solve(zero-len,one,limit,false))%M;
    //         }
    //     }
    //     else{
    //         for(int len=1;len<=min(limit,one);len++){
    //             result=(result+solve(zero,one-len,limit,true))%M;
    //         }
    //     }
    //     return dp[zero][one][wasOne]=result;
    // }

    int M=1e9+7;
    int dp[201][201][2];
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp,0,sizeof(dp));
        return solve(zero,one,limit);
    }
    int solve(int zero,int one,int limit){
        dp[0][0][1]=1;
        dp[0][0][0]=1;
        for(int onesLeft=0;onesLeft<=one;onesLeft++){
            for(int zerosLeft=0;zerosLeft<=zero;zerosLeft++){
                if(onesLeft == 0 && zerosLeft == 0) continue;
                int result=0;
                // Explore all 0's
                result = 0;
                for(int len=1;len<=min(limit,zerosLeft);len++){
                    result=(result+dp[onesLeft][zerosLeft-len][0])%M;
                }
                dp[onesLeft][zerosLeft][1]=result;

                // Explore all 1's

                result=0;
                for(int len=1;len<=min(limit,onesLeft);len++){
                    result=(result+dp[onesLeft-len][zerosLeft][1])%M;
                }
                dp[onesLeft][zerosLeft][0]=result;
            }
        }
        int startWithOne=dp[one][zero][false];
        int startWithZero=dp[one][zero][true];
        return (startWithOne+startWithZero)%M;
    }
};