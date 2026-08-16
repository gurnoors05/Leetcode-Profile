// Last updated: 8/16/2026, 7:06:59 PM
class Solution {
public:
    int dp[101][101];
    const int MOD=1e9+7;
    int numMusicPlaylists(int n, int goal, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(n,goal,k,0,0);
    }
    long solve(int n,int goal,int k,int count_song,int unique){
        if(count_song==goal){
            if(unique==n){
                return 1;
            }
            return 0;
        }
        if(dp[count_song][unique]!=-1){
            return dp[count_song][unique];
        }
        long result=0;
        if(unique<n){
            result+=(n-unique)*solve(n,goal,k,count_song+1,unique+1);
        }
        if(unique>k){
            result+=(unique-k)*solve(n,goal,k,count_song+1,unique);
        }
        return dp[count_song][unique]=result%MOD;
    }
};