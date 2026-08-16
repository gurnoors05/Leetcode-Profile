// Last updated: 8/16/2026, 6:56:39 PM
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination)
            return true;
        unordered_map<int,vector<int>> neighbours;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            neighbours[u].push_back(v);
            neighbours[v].push_back(u);
        }
        vector<bool> visited(n,false);
        return dfs(neighbours,visited,source,destination);

    }
    bool dfs(unordered_map<int,vector<int>> &neighbours,vector<bool> &visited,int start,int destination){
        if(start==destination){
            return true;
        }
        if(visited[start]==true){
            return false;
        }
        visited[start]=true;
        for(auto& neighbour:neighbours[start]){
            if(dfs(neighbours,visited,neighbour,destination)){
                return true;
            }
        }
        return false;
    }
};