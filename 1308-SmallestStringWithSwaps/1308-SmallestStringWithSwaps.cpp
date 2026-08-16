// Last updated: 8/16/2026, 7:03:40 PM
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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        int n=s.length();
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(auto& p:pairs){
            Union(p[0],p[1]);
        }
        unordered_map<int,vector<int>> mp; // Parent->all swapping elements in one group
        for(int i=0;i<n;i++){
            int find_parent=find(i);
            mp[find_parent].push_back(i);
        }
        for(auto& m:mp){
            int parent=m.first;
            vector<int> indices=m.second;
            vector<char> c;
            for(int i=0;i<indices.size();i++){
                c.push_back(s[indices[i]]);
            }
            sort(indices.begin(),indices.end());
            sort(c.begin(),c.end());
            for(int j=0;j<indices.size();j++){
                s[indices[j]]=c[j];
            }
        }
        return s;

    }
};