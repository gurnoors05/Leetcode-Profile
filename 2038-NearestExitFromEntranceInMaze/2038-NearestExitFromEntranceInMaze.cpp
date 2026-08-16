// Last updated: 8/16/2026, 6:57:13 PM
class Solution {
public:
    vector<vector<int>> directions={{-1,0},{0,-1},{1,0},{0,1}};
    int nearestExit(vector<vector<char>>& grid, vector<int>& entrance) {
         int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]});
        grid[entrance[0]][entrance[1]]='+';
        int count=0;
        int level=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                pair<int,int> p=q.front();
                q.pop();
                int i=p.first;
                int j=p.second;
                if(level!=0){
                    if(i==0 || j==0 || i==n-1 || j==m-1){
                    return level;
                    }
                }
                
                for(auto& dir:directions){
                    int new_i=i+dir[0];
                    int new_j=j+dir[1];
                    if(new_i>=0 && new_i<n && new_j>=0 && new_j<m && grid[new_i][new_j]=='.'){ 
                        grid[new_i][new_j]='+';
                        q.push({new_i,new_j});
                    }
                }
            }
            level++;
        }
        
        return -1;
    }
};