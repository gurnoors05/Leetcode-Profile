// Last updated: 8/16/2026, 6:50:44 PM
class Solution {
public:
    int dp[501][501][3];
    int maximumAmount(vector<vector<int>>& coins) {
        int k=2;
        for(int i = 0; i < 501; i++) {
            for(int j = 0; j < 501; j++) {
                for(int k = 0; k < 3; k++) {
                    dp[i][j][k] = INT_MIN;
                }
            }
        }
        return solve(0,0,coins,k);
    }
    int solve(int i,int j,vector<vector<int>> &coins,int k){
        int n=coins.size();
        int m=coins[0].size();
        if(i==n-1 && j==m-1){
            if(coins[i][j]<0 && k>0){
                return 0;
            }
            return coins[i][j];
        }
        if(i >= n || j >= m) {
            return INT_MIN;
        }
        if(dp[i][j][k]!=INT_MIN){
            return dp[i][j][k];
        }
        int take = coins[i][j]+max(solve(i+1,j,coins,k),solve(i,j+1,coins,k));
        int skip=INT_MIN;
        if(coins[i][j]<0 && k>0){
            int skipRight=solve(i+1,j,coins,k-1);
            int skipDown=solve(i,j+1,coins,k-1);
            skip=max(skipRight,skipDown);
        }
        return dp[i][j][k]=max(take,skip);
    }
};