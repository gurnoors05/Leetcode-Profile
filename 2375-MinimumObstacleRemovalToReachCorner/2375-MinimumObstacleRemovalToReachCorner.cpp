// Last updated: 8/16/2026, 6:55:14 PM
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> directions={{-1,0},{0,1},{0,-1},{1,0}};
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        vector<vector<int>> result(n,vector<int>(m,INT_MAX));
        result[0][0]=0;
        while(!pq.empty()){
            int dis=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            for(auto& dir:directions){
                int x=i+dir[0];
                int y=j+dir[1];
                if(x<0 || x>=n || y<0 || y>=m){
                    continue;
                }
                int neighDis=grid[x][y]==1?1:0;
                if(dis+neighDis<result[x][y]){
                    result[x][y]=dis+neighDis;
                    pq.push({dis+neighDis,{x,y}});
                }
            }
        }
        return result[n-1][m-1];
    }
};