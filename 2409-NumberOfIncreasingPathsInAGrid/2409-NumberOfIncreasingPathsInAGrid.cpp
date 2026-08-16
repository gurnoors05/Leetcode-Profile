// Last updated: 8/16/2026, 6:55:02 PM
class Solution {
public:
    int dp[1001][1001];
    const int MOD=1e9+7;
    vector<vector<int>> directions={{-1,0},{1,0},{0,-1},{0,1}};
    int countPaths(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=(ans+solve(grid,i,j))%MOD;
            }
        }
        return ans;
    }
    int solve(vector<vector<int>>& grid,int i,int j){
        int ans=1;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        for(auto& dir:directions){
            int new_i=i+dir[0];
            int new_j=j+dir[1];
            if(new_i>=0 && new_i<grid.size() && new_j>=0 && new_j<grid[0].size() && grid[new_i][new_j]>grid[i][j]){
                ans=(ans+solve(grid,new_i,new_j))%MOD;
            }
        }
        return dp[i][j]=ans;
    }
};