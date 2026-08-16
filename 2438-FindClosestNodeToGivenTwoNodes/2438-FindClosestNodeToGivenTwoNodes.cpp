// Last updated: 8/16/2026, 6:54:59 PM
class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int> distance1(n,INT_MAX);
        vector<int> distance2(n,INT_MAX);
        vector<bool> visited1(n,false);
        vector<bool> visited2(n,false);
        distance1[node1]=0;
        distance2[node2]=0;
        dfs(edges,node1,visited1,distance1);
        dfs(edges,node2,visited2,distance2);
        int minNode=-1;
        int minDis=INT_MAX;
        for(int i=0;i<edges.size();i++){
            int max_dist=max(distance1[i],distance2[i]);
            if(minDis>max_dist){
                minNode=i;
                minDis=max_dist;
            }
        }
        return minNode;
    }
    void dfs(vector<int>& edges,int u,vector<bool>& visited,vector<int>& distance){
        visited[u]=true;
        int v=edges[u];
        if(v!=-1 && !visited[v]){
            visited[v]=true;
            distance[v]=1+distance[u];
            dfs(edges,v,visited,distance);
        }
    }
};