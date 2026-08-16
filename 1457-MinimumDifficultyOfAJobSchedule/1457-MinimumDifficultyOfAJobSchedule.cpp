// Last updated: 8/16/2026, 7:02:01 PM
class Solution {
public:
    int dp[301][11];
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d)
            return -1;
        memset(dp,-1,sizeof(dp));
        return solve(jobDifficulty,d,0);
    }
    int solve(vector<int>& jobDifficulty, int d,int idx){
        int n=jobDifficulty.size();
        if(d==1){
            return *max_element(begin(jobDifficulty)+idx,end(jobDifficulty));
        }
        if(dp[idx][d]!=-1){
            return dp[idx][d];
        }
        int max_element=INT_MIN;
        int result=INT_MAX;
        for(int i=idx;i<=n-d;i++){
            max_element=max(max_element,jobDifficulty[i]);
            int ans=max_element+solve(jobDifficulty,d-1,i+1);
            result=min(result,ans);
        }
        return dp[idx][d]=result;
    }
};