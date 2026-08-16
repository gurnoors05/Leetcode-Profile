// Last updated: 8/16/2026, 7:03:24 PM
class Solution {
public:
    int n,m;
    vector<vector<int>> directions{{-1,0},{0,-1},{1,0},{0,1}};
    int getMaximumGold(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int maxAns=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxAns=max(maxAns,solve(grid,i,j));
            }
        }
        return maxAns;
    }
    int solve(vector<vector<int>>& grid,int i,int j){
        if(i>=n || i<0 || j<0 || j>=m || grid[i][j]==0){
            return 0;
        }
        int originalVal=grid[i][j];
        int maxVal=0;
        grid[i][j]=0; // do
        for(auto& dir:directions){
            int new_i=i+dir[0];
            int new_j=j+dir[1];
            maxVal=max(maxVal,solve(grid,new_i,new_j)); //explore
        }
        grid[i][j]=originalVal; // undo
        return maxVal+originalVal;
    }
};