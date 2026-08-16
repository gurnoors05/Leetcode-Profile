// Last updated: 8/16/2026, 6:54:00 PM
class Solution {
public:
    int result=INT_MAX;
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int dis=roads[i][2];
            adj[u].push_back({v,dis});
            adj[v].push_back({u,dis});
        }
        vector<bool> visited(n,false);
        dfs(adj,visited,1);
        return result;
    }
    void dfs(unordered_map<int,vector<pair<int,int>>>& adj,vector<bool> &visited,int u){
        visited[u]=true;
        for(auto& it:adj[u]){
            int v=it.first;
            int dis=it.second;
            result=min(result,dis);
            if(!visited[v]){
                dfs(adj,visited,v);
            }
        }

    }

};