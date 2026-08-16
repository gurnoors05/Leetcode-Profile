// Last updated: 8/16/2026, 6:55:04 PM
class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int u){
        if(parent[u]==u){
            return u;
        }
        return parent[u]=find(parent[u]);
    }
    void findunion(int u,int v){
        int parent_u=find(u);
        int parent_v=find(v);
        if(parent_u==parent_v){
            return;
        }
        if(rank[parent_u]>rank[parent_v]){
            parent[parent_v]=parent_u;
        }
        else if(rank[parent_v]>rank[parent_u]){
            parent[parent_u]=parent_v;
        }
        else{
            parent[parent_v]=parent_u;
            rank[parent_u]++;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(auto& edge:edges){
            int u=edge[0];
            int v=edge[1];
            findunion(u,v);
        }
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            int parent_i=find(i);
            mp[parent_i]++;
        }
        long long result=0;
        long long remaining_nodes=n;
        for(auto& it:mp){
            long long size = it.second;
            result+=size*(remaining_nodes-size);
            remaining_nodes -= size;
        }
        return result;
    }
};