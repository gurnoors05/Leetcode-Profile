// Last updated: 8/16/2026, 7:05:39 PM
class Solution {
public:
    void dfs(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& directions,vector<vector<int>>& visited){
        visited[i][j]=1;
        int n=grid.size();
        int m=grid[0].size();
        for(vector<int>& dir:directions){
            int new_i=i+dir[0];
            int new_j=j+dir[1];
            if(new_i>=0 && new_i<n && new_j>=0 && new_j<m && !visited[new_i][new_j] && grid[new_i][new_j]==1){
                dfs(grid,new_i,new_j,directions,visited);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> directions={{-1,0},{1,0},{0,-1},{0,1}};
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            if(!visited[0][j] && grid[0][j]==1){
                dfs(grid,0,j,directions,visited);
            }
            if(!visited[n-1][j] && grid[n-1][j]==1){
                dfs(grid,n-1,j,directions,visited);
            }
        }
        for(int i=0;i<n;i++){
            if(!visited[i][0] && grid[i][0]==1){
                dfs(grid,i,0,directions,visited);
            }
            if(!visited[i][m-1] && grid[i][m-1]==1){
                dfs(grid,i,m-1,directions,visited);
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
        
    }
};