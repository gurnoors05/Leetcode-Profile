// Last updated: 8/16/2026, 7:00:26 PM
class Solution {
public:
    // Using min max theory, but it will TLE
    // int dp[100001][2];
    // bool winnerSquareGame(int n) {
    //     memset(dp,-1,sizeof(dp));
    //     int ans= solve(n,1);
    //     if(ans==1){
    //         return true;
    //     }
    //     return false;
    // }
    // int solve(int n,int turn){
    //     if(n==0){
    //         if(turn==0){
    //             return +1; // it was bob's turn but n has become 0, so alice's win
    //         }
    //         else if(turn==1){
    //             return -1;
    //         }
    //     }
    //     if(dp[n][turn]!=-1){
    //         return dp[n][turn];
    //     }
    //     int result=INT_MIN;
    //     if (turn == 1) { // Alice's turn → maximize
    //         int best = -1; // assume Alice loses
    //         for (int k = 1; k * k <= n; k++) {
    //             int next = solve(n - k*k, 0);
    //             best = max(best, next);
    //             if (best == 1) break; // Alice found a winning path
    //         }
    //         return dp[n][turn]=best;
    //     }
    //     else{ // Minimize in bob's turn
    //         int best=1;
    //         for(int k=1;k*k<=n;k++){
    //             int next=solve(n-k*k,1);
    //             best=min(best,next);
    //             if(best==-1){
    //                 break;
    //             }
    //         }
    //         return dp[n][turn]=best;
    //     }

        vector<int> memo;
        bool winnerSquareGame(int n){
            memo.assign(n+1, -1);
            return solve(n);
        }
        int solve(int n){
            if(n==0){
                return 0;
            }
            if (memo[n] != -1) return memo[n];

            for(int k=1;k*k<=n;k++){
                if(solve(n-k*k)==0){ // If at next step(bob's turn), it comes 0(means n=0), return 1(alice won)
                    return memo[n]= 1;
                }
            }
            return memo[n]=0;
        }
    
};