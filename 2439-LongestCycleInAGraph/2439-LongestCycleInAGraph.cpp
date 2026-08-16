// Last updated: 8/16/2026, 6:54:58 PM
class Solution {
public:
    int result=-1;
    int longestCycle(vector<int>& edges) {
        vector<bool> visited(edges.size(),false);
        vector<bool> inRecursion(edges.size(),false);
        vector<int> dist(edges.size(),1);
        for(int i=0;i<edges.size();i++){
            if(!visited[i]){
                dfs(i,edges,visited,inRecursion,dist);
            }
        }
        return result;
    }
    void dfs(int u,vector<int>& edges,vector<bool> &visited,vector<bool>& inRecursion,vector<int> &dist){
        
        if(u!=-1){
            visited[u]=true;
            inRecursion[u]=true;
            int v=edges[u];
            if(v!=-1 && !visited[v]){
                dist[v]=dist[u]+1;
                dfs(v,edges,visited,inRecursion,dist);
            }
            else if(v!=-1 && inRecursion[v]==true){
                result=max(result,dist[u]-dist[v]+1);
            }
            inRecursion[u]=false;
        }
    }
};