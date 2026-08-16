// Last updated: 8/16/2026, 7:07:13 PM
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int,vector<int>> adj;
        for(auto& vec:dislikes){
            int u=vec[0];
            int v=vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);

        }

        vector<int> colored(n+1,-1);
        for(int i=1;i<=n;i++){
            if(colored[i]==-1){
                if(!dfs(adj,colored,i,1)){
                    return false;
                }
            }
        }
        return true;
    }
    bool dfs(unordered_map<int,vector<int>>& adj,vector<int>& colored,int u,int color){
        colored[u]=color;
        for(auto& v:adj[u]){
            if(colored[v]==color){
                return false;
            }
            if(colored[v]==-1){
                if(!dfs(adj,colored,v,1-color)){
                    return false;
                }
            }
        }
        return true;
    }

};