// Last updated: 8/16/2026, 7:01:14 PM
class Solution {
public:
    int dp[500001][2];
    // Using min max theory like Stone Game 2
    string stoneGameIII(vector<int>& stoneValue) {
        memset(dp,-1,sizeof(dp));
        int diff=solve(stoneValue,0,1);

        if(diff<0){
            return "Bob";
        }
        else if(diff>0){
            return "Alice";
        }
        return "Tie";
    }
    int solve(vector<int>& stoneValue,int i,int turn){
        int n=stoneValue.size();
        if(i>=n){
            return 0;
        }
        if(dp[i][turn]!=-1){
            return dp[i][turn];
        }
        int result=(turn==1)?INT_MIN:INT_MAX;
        int stones=0;
        for(int j=i;j<min(i+3,n);j++){
            if(turn==1){
                stones+=stoneValue[j];
                result=max(result,stones + solve(stoneValue,j+1,0));
            }
            else if(turn==0){
                stones-=stoneValue[j];
                result=min(result,stones + solve(stoneValue,j+1,1));
            }
        }
        return dp[i][turn]=result;
    }
};