// Last updated: 8/16/2026, 7:07:23 PM
class Solution {
public:
    int size;
    int dp[101][101][101];
    const int MOD=1e9+7;
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        size=group.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,n,minProfit,group,profit);
    }
    int solve(int i,int currentProfit,int currentPeople,int n, int minProfit, vector<int>& group, vector<int>& profit){
        if(currentPeople > n){
            return 0;
        }
        if(i==size){
            if(currentProfit>=minProfit){
                return dp[i][currentProfit][currentPeople] = 1;
            }
            return dp[i][currentProfit][currentPeople] = 0;
        }
        if(dp[i][currentProfit][currentPeople]!=-1){
            return dp[i][currentProfit][currentPeople];
        }
        int not_take=solve(i+1,currentProfit,currentPeople,n,minProfit,group,profit)%MOD;
        int take=solve(i+1,min(currentProfit+profit[i], minProfit),currentPeople+group[i],n,minProfit,group,profit)%MOD;
        return  dp[i][currentProfit][currentPeople] = (take%MOD + not_take%MOD)%MOD;
    }
};