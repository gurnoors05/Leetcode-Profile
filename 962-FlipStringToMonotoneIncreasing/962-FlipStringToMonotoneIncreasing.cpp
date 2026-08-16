// Last updated: 8/16/2026, 7:06:53 PM
class Solution {
public:
    int n;

    int minFlipsMonoIncr(string s) {
        n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return solve(s,0,0,dp);
    }
    int solve(string &s,int idx,int prev,vector<vector<int>> &dp){
        if(idx>=n){
            return 0;
        }
        if(dp[idx][prev]!=-1){
            return dp[idx][prev];
        }
        int flip=INT_MAX;
        int no_flip=INT_MAX;
        if(s[idx]=='1'){
            if(prev==1){
                no_flip=solve(s,idx+1,1,dp);
            }
            else{
                flip=1+solve(s,idx+1,0,dp);
                no_flip=solve(s,idx+1,1,dp);
            }
        }
        else if(s[idx]=='0'){
            if(prev==1){
                flip=1+solve(s,idx+1,1,dp);
            }
            else{
                flip=1+solve(s,idx+1,1,dp);
                no_flip=solve(s,idx+1,0,dp);
            }
        }
        return dp[idx][prev]=min(flip,no_flip);
    }
};