// Last updated: 8/16/2026, 6:50:21 PM
class DSU{
public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int u){
        if(u==parent[u]){
            return u;
        }
        return parent[u]=find(parent[u]);
    }
    void findunion(int u,int v){
        int u_parent=find(u);
        int v_parent=find(v);

        if(u_parent==v_parent) return;

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
};
bool check(int n, vector<vector<int>>& edges, int k,int mid){
    DSU dsu(n);
    vector<pair<int,int>> upgraded_edges;
    for(auto& edge:edges){
            int u=edge[0];
            int v=edge[1];
            int s=edge[2];
            int m=edge[3];
            if(m==1){
                if(s<mid){
                    return false;
                }
                dsu.findunion(u,v);  
            }
            else{
                if(s>=mid){
                    dsu.findunion(u,v);
                }
                else if(s*2>=mid){
                    upgraded_edges.push_back({u,v});
                }
            }
    }
    for(auto &it:upgraded_edges){
        int u=it.first;
        int v=it.second;
        if(dsu.find(u)!=dsu.find(v)){
            if(k<=0){
                return false;
            }
            dsu.findunion(u,v);
            k--;
        }
    }
    int root=dsu.find(0);
    for(int i=1;i<=n-1;i++){
        if(dsu.find(i)!=root){
            return false;
        }
    }
    return true;
}
class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        DSU dsu(n);
        for(auto& edge:edges){
            int u=edge[0];
            int v=edge[1];
            int s=edge[2];
            int m=edge[3];
            if(m==1){
                if(dsu.find(u)==dsu.find(v)){ // Cycle present
                    return -1;
                }
                else{
                    dsu.findunion(u,v);
                }
            }
        }
        int l=1;
        int r=2*1000001;
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(n,edges,k,mid)){
                l=mid+1;
                ans=mid;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};