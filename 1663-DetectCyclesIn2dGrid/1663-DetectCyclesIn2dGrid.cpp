// Last updated: 8/16/2026, 7:00:03 PM
class Solution {
public:
    vector<vector<int>> directions={{-1,0},{0,-1},{1,0},{0,1}};
    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && dfs(grid,visited,i,j,-1,-1)){
                    return true;   
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& grid,vector<vector<bool>> &visited,int i,int j,int prev_i,int prev_j){
        int n=grid.size();
        int m=grid[0].size();
        visited[i][j]=true;
        for(auto& dir:directions){
            int new_i=i+dir[0];
            int new_j=j+dir[1];
            if(new_i<0 || new_i>=n || new_j<0 || new_j>=m){
                continue;
            }
            if(grid[new_i][new_j]!=grid[i][j]){
                continue;
            }
            if(visited[new_i][new_j] && !(new_i==prev_i && new_j==prev_j)){
                return true;
            }
            if(!visited[new_i][new_j]){
                if(dfs(grid,visited,new_i,new_j,i,j)){
                    return true;
                }
            }
            
        }
        return false;
    }
};