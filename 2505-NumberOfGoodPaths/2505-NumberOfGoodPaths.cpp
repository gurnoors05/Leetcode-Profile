// Last updated: 8/16/2026, 6:54:27 PM
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
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size();
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        map<int,vector<int>> val_to_node;
        for(int i=0;i<vals.size();i++){
            val_to_node[vals[i]].push_back(i);
        }

        int result=n;
        vector<bool> is_active(vals.size(),false);
        for(auto& it:val_to_node){
            vector<int> nodes=it.second;
            for(auto& u:nodes){
                for(auto& v:adj[u]){
                    if(is_active[v]){
                        findunion(u,v);
                    }
                }
                is_active[u]=true;
            }
            vector<int> parent_of_u;
            for(auto& u:nodes){
                int parent=find(u);
                parent_of_u.push_back(parent);
            }
            sort(begin(parent_of_u),end(parent_of_u));
            int size=parent_of_u.size();
            for(int i=0;i<parent_of_u.size();i++){
                int curr_parent=parent_of_u[i];
                int count=0;
                while(i<size && parent_of_u[i]==curr_parent){
                    count++;
                    i++;
                }
                i--;
                result+=(count*(count-1))/2;
            }
        }
        return result;
    }
};