// Last updated: 8/16/2026, 7:00:40 PM
class Solution {
public:
    int count=0;
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back({v,1});
            adj[v].push_back({u,0});
        }
        vector<bool> visited(n,false);
        dfs(adj,visited,0);
        return count;
    }
    void dfs(unordered_map<int,vector<pair<int,int>>>& adj,vector<bool> &visited,int u){
        visited[u]=true;
        for(auto& it:adj[u]){
            int v=it.first;
            int sign=it.second;
            if(!visited[v]){
                count+=sign;
                dfs(adj,visited,v);
            }
        }
    }
};