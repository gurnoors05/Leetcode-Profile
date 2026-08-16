// Last updated: 8/16/2026, 7:06:43 PM
class Solution {
public:
vector<int> parent;
    vector<int> rank;
    int find(int u){
        if(parent[u]==u){
            return parent[u];
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
        else if(rank[v_parent]>rank[u_parent]){
            parent[u_parent]=v_parent;
        }
        else{
             parent[v_parent]=u_parent;
             rank[u_parent]++;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    Union(i,j);
                }
            }
        }
        int groups=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                groups++;
            }
        }
        return n-groups;
    }
};