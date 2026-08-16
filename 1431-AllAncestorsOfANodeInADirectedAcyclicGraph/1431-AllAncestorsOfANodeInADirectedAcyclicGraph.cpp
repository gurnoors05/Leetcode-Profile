// Last updated: 8/16/2026, 7:02:34 PM
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> result(n);
        unordered_map<int,vector<int>> adj;
        for(auto& edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
        }
        for(int i=0;i<n;i++){
            int ancestor=i;
            dfs(ancestor,i,adj,result);
        }
        return result;
    }
    void dfs(int ancestor,int u,unordered_map<int,vector<int>> &adj,vector<vector<int>>& result){
        for(auto& neigh:adj[u]){
            if(result[neigh].empty() || result[neigh].back()!=ancestor){
                result[neigh].push_back(ancestor);
                dfs(ancestor,neigh,adj,result);
            }
        }
    }
};