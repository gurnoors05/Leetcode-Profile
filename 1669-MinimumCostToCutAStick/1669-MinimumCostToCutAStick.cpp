// Last updated: 8/16/2026, 6:59:54 PM
class Solution {
public:
    int dp[102][102];
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        int size=cuts.size();
        memset(dp,-1,sizeof(dp));
        return solve(cuts,n,0,size-1);
    }
    int solve(vector<int>& cuts,int n,int i,int j){
        if(j-i<2){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int mini=INT_MAX;
        for(int idx=i+1;idx<j;idx++){
            int cost=cuts[j]-cuts[i];
            int remaining=solve(cuts,n,i,idx)+solve(cuts,n,idx,j);
            mini=min(mini,cost+remaining);
        }
        return dp[i][j]=mini;
    }

};