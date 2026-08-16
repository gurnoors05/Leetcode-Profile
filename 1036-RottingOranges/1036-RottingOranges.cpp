// Last updated: 8/16/2026, 7:06:02 PM
class Solution {
public:
    vector<vector<int>> directions{{-1,0},{0,-1},{1,0},{0,1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int rotten=0;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    count++;
                    
                }
                else if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        if(count==0){
            return 0;
        }
        int count2=0;
        int level=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                for(auto& dir:directions){
                    int new_i=i+dir[0];
                    int new_j=j+dir[1];
                    if(new_i>=0 && new_i<n && new_j>=0 && new_j<m && grid[new_i][new_j]==1){
                        q.push({new_i,new_j});
                        count2++;
                        grid[new_i][new_j]=2;
                    }
                }
            
            }
            level++;
        }
        if(count==count2){
            return level-1;
        }
        return -1;
    }
};