// Last updated: 8/16/2026, 7:05:20 PM
class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
     
        unordered_map<int,vector<int>> adj;
        for(auto& p:paths){
            int u=p[0];
            int v=p[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> color(n+1,-1);
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                dfs(adj,color,i);
            }
        }
        color.erase(color.begin());
        return color;
    }
    void dfs(unordered_map<int,vector<int>>& adj,vector<int> &color,int u){
        vector<bool> used(5,false);
        for(auto& v:adj[u]){
            if(color[v]!=-1){
                used[color[v]]=true;
            }
        }
        for(int i=1;i<5;i++){
            if(used[i]==false){
                color[u]=i;
                break;
            }
        }
        for(auto& v:adj[u]){
            if(color[v]==-1){
                dfs(adj,color,v);
            }
        }
    }

};