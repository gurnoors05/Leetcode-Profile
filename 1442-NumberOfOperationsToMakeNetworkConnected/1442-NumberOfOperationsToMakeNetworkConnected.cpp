// Last updated: 8/16/2026, 7:02:25 PM
class Solution {
public:
vector<int> parent;
        vector<int> rank;
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        rank.resize(n,0);
        if (connections.size() < n - 1) return -1; 
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        int components=n;
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            int u_parent=find(parent,u);
            int v_parent=find(parent,v);
            if(u_parent!=v_parent){
                findUnion(u_parent,v_parent);
                components--;
            }

        }
        return components-1;
    }
    int find(vector<int> &parent,int u){
        if(u==parent[u]){
            return u;
        }
        return parent[u]=find(parent,parent[u]);
    }
    void findUnion(int u,int v){
        if(rank[u]>rank[v]){
            parent[v]=u;
        }
        else if(rank[u]<rank[v]){
            parent[u]=v;
        }
        else{
            rank[u]++;
            parent[v]=u;
        }

    }
};