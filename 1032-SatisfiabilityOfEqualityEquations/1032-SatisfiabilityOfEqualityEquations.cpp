// Last updated: 8/16/2026, 7:06:13 PM
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
    bool equationsPossible(vector<string>& equations) {
        int n=equations.size();
        parent.resize(26);
        rank.resize(26,0);
        for(int i=0;i<26;i++){
            parent[i]=i;
        }
        for(int i=0;i<equations.size();i++){
            string s=equations[i];
            char e=s[1];
            if(e=='='){
                Union(s[0]-'a',s[3]-'a');
            }
        
        }
        for(int i=0;i<equations.size();i++){
            string s=equations[i];
            char e=s[1];
            if(e=='!'){
                int u_parent=find(s[0]-'a');
                int v_parent=find(s[3]-'a');
                if(u_parent==v_parent){
                    return false;
                }
            }
         }
        return true;
    }
};