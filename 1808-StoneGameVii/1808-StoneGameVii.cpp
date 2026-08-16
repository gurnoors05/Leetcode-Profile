// Last updated: 8/16/2026, 6:58:36 PM
class Solution {
public:
    int dp[1001][1001];
    int stoneGameVII(vector<int>& stones) {
        int n=stones.size();
        vector<int> prefix(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+stones[i];
            cout<<prefix[i+1]<<" ";
        }
        memset(dp,-1,sizeof(dp));
        return solve(stones,prefix,0,n-1);
    }
    int solve(vector<int>& stones,vector<int>& prefix,int i,int j){
        if(i==j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int left_pick=(prefix[j+1]-prefix[i+1])-solve(stones,prefix,i+1,j);
        int right_pick=(prefix[j]-prefix[i])-solve(stones,prefix,i,j-1);
        return dp[i][j]=max(left_pick,right_pick);
    }
};