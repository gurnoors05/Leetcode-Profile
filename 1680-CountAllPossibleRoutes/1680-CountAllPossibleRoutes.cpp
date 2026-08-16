// Last updated: 8/16/2026, 6:59:51 PM
class Solution {
public:
    const int MOD=1e9+7;
    int dp[101][201];
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(dp,-1,sizeof(dp));
        return solve(locations,start,finish,fuel);
    }
    int solve(vector<int>& locations, int startCity, int finish, int fuel){
        if(fuel<0){
            return 0;
        }
        if(dp[startCity][fuel]!=-1){
            return dp[startCity][fuel];
        }
        int ans=0;
        if(startCity==finish){
            ans+=1;
        }
        for(int nextCity=0;nextCity<locations.size();nextCity++){
            if(nextCity!=startCity){
                int fuelGone=abs(locations[startCity]-locations[nextCity]);
                ans=(ans+solve(locations,nextCity,finish,fuel-fuelGone))%MOD;
            }
        }
        return dp[startCity][fuel]=ans;
    }
};