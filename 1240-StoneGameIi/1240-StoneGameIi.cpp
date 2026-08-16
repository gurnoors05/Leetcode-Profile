// Last updated: 8/16/2026, 7:04:22 PM
class Solution {
public:
    int dp[101][101][2];
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        return solve(piles,0,1,1);
    }
    int solve(vector<int> &piles,int i,int m,int turn){
        int n=piles.size();
        if(i==piles.size()){
            return 0;
        }
        if(dp[i][m][turn]!=-1){
            return dp[i][m][turn];
        }
        int stones=0;
        int ans=(turn==1)?INT_MIN:INT_MAX;
        for(int x=1;x<=min(2*m,n-i);x++){
            stones+=piles[i+x-1];
            if(turn==1){
                ans=max(ans,stones+solve(piles,i+x,max(m,x),0));
            }
            else{
                ans=min(ans,solve(piles,i+x,max(m,x),1));
            }
        }
        return dp[i][m][turn]=ans;
    }
};