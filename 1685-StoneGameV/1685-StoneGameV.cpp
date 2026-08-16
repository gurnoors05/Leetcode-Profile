// Last updated: 8/16/2026, 6:59:49 PM
class Solution {
public:
    int dp[501][501];
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int> prefix(n+1,0);
        for (int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + stoneValue[i];
        }
        memset(dp,-1,sizeof(dp));
        return solve(prefix,0,n-1);
    }
    int solve(vector<int>& prefix,int l,int r){
        if(l==r){
            return 0;
        }
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        int best=0;
        for(int i=l;i<r;i++){
            int leftSum=prefix[i+1]-prefix[l];
            int rightSum=prefix[r+1]-prefix[i+1];
            if(leftSum<rightSum){
                best=max(best,leftSum+solve(prefix,l,i));
            }
            else if(leftSum>rightSum){
                best=max(best,rightSum+solve(prefix,i+1,r));
            }
            else{
                best=max(best, max(leftSum + solve(prefix,l, i), rightSum + solve(prefix,i+1, r)));
            }
        }
        return dp[l][r]=best;
    }
};