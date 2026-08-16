// Last updated: 8/16/2026, 7:01:33 PM
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        sort(satisfaction.begin(),satisfaction.end());
        return solve(satisfaction,0,1,n,dp);
    }
    int solve(vector<int>& satisfaction,int i,int time,int n,vector<vector<int>>& dp){
        if(i==n){
            return 0;
        }
        if(dp[i][time]!=-1){
            return dp[i][time];
        }
        int take=satisfaction[i]*time+solve(satisfaction,i+1,time+1,n,dp);
        int not_take=solve(satisfaction,i+1,time,n,dp);
        return dp[i][time]=max(take,not_take);
    }
};