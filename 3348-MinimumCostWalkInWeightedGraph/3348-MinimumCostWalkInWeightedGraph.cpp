// Last updated: 8/16/2026, 6:51:57 PM
class Solution {
public:
    vector<int> parent;
    int find(int u){
        if(u==parent[u]){
            return u;
        }
        return parent[u]=find(parent[u]);
    }
    void findUnion(int u,int v){
        parent[v]=u;
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n);
        vector<int> cost(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            cost[i]=-1;
        }
        for(auto& edge:edges){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            int u_parent=find(u);
            int v_parent=find(v);
            if(u_parent!=v_parent){
                cost[u_parent]&=cost[v_parent];
                findUnion(u_parent,v_parent);
            }
            cost[u_parent]&=w;
        }
        vector<int> result;

        for(auto& q:query){
            int u=q[0];
            int v=q[1];
            int u_parent=find(u);
            int v_parent=find(v);
            if(u==v){
                result.push_back(0);
            }
            else if(u_parent!=v_parent){
                result.push_back(-1);
            }
            else{
                result.push_back(cost[u_parent]);
            }
        }
        return result;

    }
};