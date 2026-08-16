// Last updated: 8/16/2026, 6:58:32 PM
class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int u){
        if(u==parent[u]){
            return u;
        }
        return parent[u]=find(parent[u]);
    }
    void findunion(int u,int v){
        int u_parent=find(u);
        int v_parent=find(v);
        if(u_parent==v_parent){
            return;
        }
        if(rank[u_parent]>rank[v_parent]){
            parent[v_parent]=u_parent;
        }
        else if(rank[u_parent]>rank[v_parent]){
            parent[u_parent]=v_parent;
        }
        else{
            parent[v_parent]=u_parent;
            rank[u_parent]++;
        }
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<queries.size();i++){
            queries[i].push_back(i);
        }
        auto lambda= [&](vector<int>& v1,vector<int>& v2){
            return v1[2]<v2[2];
        };
        sort(begin(edgeList),end(edgeList),lambda);
        sort(begin(queries),end(queries),lambda);
        vector<bool> result(queries.size());
        int j=0;
        for(int i=0;i<queries.size();i++){
            while(j<edgeList.size() && edgeList[j][2]<queries[i][2]){
                findunion(edgeList[j][0],edgeList[j][1]);
                j++;
            }
            result[queries[i][3]]=find(queries[i][0])==find(queries[i][1]);
        }
        return result;
    }
};