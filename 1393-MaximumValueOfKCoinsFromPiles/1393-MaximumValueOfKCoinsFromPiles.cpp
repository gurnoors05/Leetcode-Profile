// Last updated: 8/16/2026, 7:02:57 PM
class Solution {
public:
    int dp[1001][2001];
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(piles,k,0);
    }
    int solve(vector<vector<int>>& piles, int k,int i){
        if(i>=piles.size()){
            return 0;
        }
        if(dp[i][k]!=-1){
            return dp[i][k];
        }
        int not_taken=solve(piles,k,i+1);
        int taken=0;
        int sum=0;
        for(int j=0;j<min((int)piles[i].size(),k);j++){
            sum+=piles[i][j];
            if(k-(j+1)>=0){
                int result=sum+solve(piles,k-(j+1),i+1);
                taken=max(taken,result);
            }
        }
        return dp[i][k]=max(taken,not_taken);
    }
};