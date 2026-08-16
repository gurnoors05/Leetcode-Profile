// Last updated: 8/16/2026, 7:00:55 PM
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return dfs(adj,hasApple,0,-1);
    }
    int dfs( unordered_map<int,vector<int>> &adj,vector<bool>& hasApple,int start,int previous){
        int time=0;
        for(auto& v:adj[start]){
            if(v==previous){
                continue;
            }
            int timeByChild=dfs(adj,hasApple,v,start);
            if(timeByChild || hasApple[v]){ // Means time by child is not zero
                time+=2+timeByChild;
            }
        }
        return time;
    }

};