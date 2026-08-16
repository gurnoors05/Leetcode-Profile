// Last updated: 8/16/2026, 7:06:30 PM
class Solution {
public:
    int dp[21][10001];
    int tallestBillboard(vector<int>& rods) {
        int n=rods.size();
        memset(dp,-1,sizeof(dp));
        return solve(rods,0,0,n)/2; //Imp.------ Divide by 2
    }
    int solve(vector<int>& rods,int i,int diff,int n){
        if(i==n){
            if(diff==0){
                return 0;
            }
            return INT_MIN;
        }
        if(dp[i][diff+5000]!=-1){
            return dp[i][diff+5000];
        }
        int take_nothing=solve(rods,i+1,diff,n);
        int take_rod1=rods[i]+solve(rods,i+1,diff+rods[i],n);
        int take_rod2=rods[i]+solve(rods,i+1,diff-rods[i],n);
        return dp[i][diff+5000]=max({take_nothing,take_rod1,take_rod2});
    }
};