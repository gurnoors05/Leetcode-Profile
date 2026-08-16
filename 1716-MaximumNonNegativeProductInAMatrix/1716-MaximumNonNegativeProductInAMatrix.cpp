// Last updated: 8/16/2026, 6:59:37 PM
class Solution {
public:
    int MOD=1e9+7;
    vector<vector<pair<long long,long long>>> dp;
    int maxProductPath(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        dp= vector<vector<pair<long long,long long>>>(n,vector<pair<long long,long long>>(m,{LLONG_MIN,LLONG_MAX}));
        auto [maxProduct,minProduct]=solve(0,0,grid);
        return maxProduct<0?-1:maxProduct%MOD;
    }
    pair<long long, long long> solve(int i,int j,vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        if(i==n-1 && j==m-1){
            return {grid[i][j],grid[i][j]};
        }
        if(dp[i][j]!=make_pair(LLONG_MIN,LLONG_MAX)){
            return dp[i][j];
        }
        long long max_value=LLONG_MIN;
        long long min_value=LLONG_MAX;
        if(i+1<n){
            auto [downMax,downMin]=solve(i+1,j,grid);
            max_value=max({max_value,grid[i][j]*downMax,grid[i][j]*downMin});
            min_value=min({min_value,grid[i][j]*downMax,grid[i][j]*downMin});
        }
        if(j+1<m){
            auto [rightMax,rightMin]=solve(i,j+1,grid);
            max_value=max({max_value,grid[i][j]*rightMax,grid[i][j]*rightMin});
            min_value=min({min_value,grid[i][j]*rightMax,grid[i][j]*rightMin});
        }
        return dp[i][j]={max_value,min_value};
    }
};