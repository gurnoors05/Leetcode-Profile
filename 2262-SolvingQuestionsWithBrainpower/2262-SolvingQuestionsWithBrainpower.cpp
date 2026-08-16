// Last updated: 8/16/2026, 6:55:40 PM
class Solution {
public:
    long long dp[100001];
    long long mostPoints(vector<vector<int>>& questions) {
        memset(dp,-1,sizeof(dp));
        return solve(questions,0);
    }
    long long solve(vector<vector<int>>& questions,int i){
        if(i>=questions.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        long long take=0;
        long long skip=0;
        take=questions[i][0]+solve(questions,i+questions[i][1]+1);
        skip=solve(questions,i+1);
        return dp[i]=max(take,skip);
    }

};