// Last updated: 8/16/2026, 7:04:52 PM
class Solution {
public:
    vector<vector<int>> directions={{-1,0},{0,-1},{1,0},{0,1},{1,-1},{-1,1},{1,1},{-1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==1){
            return -1;
        }
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0]=1;
        int count=0;
        int level=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                pair<int,int> p=q.front();
                q.pop();
                int i=p.first;
                int j=p.second;
                if(i==n-1 && j==m-1){
                    return level+1;
                }
                for(auto& dir:directions){
                    int new_i=i+dir[0];
                    int new_j=j+dir[1];
                    if(new_i>=0 && new_i<n && new_j>=0 && new_j<m && grid[new_i][new_j]==0){ 
                        grid[new_i][new_j]=level+1;
                        q.push({new_i,new_j});
                    }
                }
            }
            level++;
        }
        
        return -1;
    }
};