// Last updated: 8/16/2026, 6:58:19 PM
class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n=source.size();
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        unordered_map<int,unordered_map<int,int>> groupWithElements;
        for(int i=0;i<allowedSwaps.size();i++){
            int u=allowedSwaps[i][0];
            int v=allowedSwaps[i][1];
            Union(u,v);
        }
        for(int i=0;i<n;i++){
            int p=find(i);
            groupWithElements[p][source[i]]++;
        }
        int hamming=0;
        for(int i=0;i<n;i++){
            int p=find(i);
            if(groupWithElements[p][target[i]]>0){
                groupWithElements[p][target[i]]--;
            }
            else{
                hamming++;
            }
        }
        return hamming;
    }
    int find(int u){
        if(parent[u]==u){
            return u;
        }
        return parent[u]=find(parent[u]);
    }
    void Union(int u,int v){
        int u_parent=find(u);
        int v_parent=find(v);
        if(u_parent==v_parent){
            return;
        }
        if(rank[u_parent]>rank[v_parent]){
            parent[v_parent]=u_parent;
        }
        else if(rank[u_parent]<rank[v_parent]){
            parent[u_parent]=v_parent;
        }
        else{
            parent[v_parent]=u_parent;
            rank[u_parent]++;
        }
    }
};