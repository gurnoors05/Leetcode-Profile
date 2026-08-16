// Last updated: 8/16/2026, 6:49:54 PM
class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(k + 1, -1)));
        int ans = solve(grid, k, 0, 0,0,dp);
        return (ans < 0) ? -1 : ans;
    }
    int solve(vector<vector<int>>& grid, int k,int i,int j,int cost,vector<vector<vector<int>>> &dp){
        int m=grid.size();
        int n=grid[0].size();
        if(i>=m || j>=n){
            return INT_MIN;
        }
        int newCost = cost + (grid[i][j] > 0);

        if(newCost > k)
            return INT_MIN;
        
        if(i == m-1 && j == n-1)
            return grid[i][j]; //score
        
        if(dp[i][j][cost] != -1) {
            return dp[i][j][cost];
        }
        int right=solve(grid,k,i,j+1,newCost,dp);
        int down=solve(grid,k,i+1,j,newCost,dp);
        
        int best = max(right, down);
        if (best == INT_MIN) return dp[i][j][cost]=INT_MIN;

        return dp[i][j][cost]=grid[i][j]+best;
    }


};