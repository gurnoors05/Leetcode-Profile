// Last updated: 8/16/2026, 6:59:14 PM
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> directions{{-1,0},{0,-1},{1,0},{0,1}};
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        q.push({0,{0,0}});
        vector<vector<int>> result(n,vector<int>(m,INT_MAX));
        while(!q.empty()){
            int dist=q.top().first;
            auto node=q.top().second;
            int i=node.first;
            int j=node.second;
            q.pop();
            if(i==n-1 && j==m-1){
                return dist;
            }
            for(auto &dir:directions){
                int new_i=i+dir[0];
                int new_j=j+dir[1];
                if(new_i>=0 && new_i<n && new_j>=0 && new_j<m){
                    int absDiff=abs(heights[new_i][new_j]-heights[i][j]);
                    int maxDiff=max(dist,absDiff);
                    if(result[new_i][new_j]>maxDiff){
                        result[new_i][new_j]=maxDiff;
                        q.push({maxDiff,{new_i,new_j}});
                    }
                }
            }
                
        }

      return 0;
    }
};