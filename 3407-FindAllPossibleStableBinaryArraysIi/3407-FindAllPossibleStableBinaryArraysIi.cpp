// Last updated: 8/16/2026, 6:51:41 PM
class Solution {
public:
    int M = 1e9+7;
    int dp[1001][1001][2];

    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp,0,sizeof(dp));
        return solve(zero,one,limit);
    }

    int solve(int zero,int one,int limit){

        for(int zerosLeft = 0; zerosLeft <= min(zero,limit); zerosLeft++)
            dp[zerosLeft][0][0] = 1;

        for(int onesLeft = 0; onesLeft <= min(one,limit); onesLeft++)
            dp[0][onesLeft][1] = 1;

        for(int zerosLeft = 0; zerosLeft <= zero; zerosLeft++){
            for(int onesLeft = 0; onesLeft <= one; onesLeft++){

                if(zerosLeft == 0 || onesLeft == 0)
                    continue;

                dp[zerosLeft][onesLeft][1] = 
                (dp[zerosLeft][onesLeft-1][0] + dp[zerosLeft][onesLeft-1][1]) % M;

                if(onesLeft-1 >= limit){
                    dp[zerosLeft][onesLeft][1] = 
                    (dp[zerosLeft][onesLeft][1] - dp[zerosLeft][onesLeft-1-limit][0] + M) % M;
                }

                dp[zerosLeft][onesLeft][0] = 
                (dp[zerosLeft-1][onesLeft][0] + dp[zerosLeft-1][onesLeft][1]) % M;

                if(zerosLeft-1 >= limit){
                    dp[zerosLeft][onesLeft][0] = 
                    (dp[zerosLeft][onesLeft][0] - dp[zerosLeft-1-limit][onesLeft][1] + M) % M;
                }
            }
        }

        return (dp[zero][one][0] + dp[zero][one][1]) % M;
    }
};