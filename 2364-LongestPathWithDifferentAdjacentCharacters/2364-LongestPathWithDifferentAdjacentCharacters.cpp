// Last updated: 8/16/2026, 6:55:20 PM
class Solution {
public:
    int result=0;
    int longestPath(vector<int>& parent, string s) {
        unordered_map<int,vector<int>> adj;
        for(int i=1;i<parent.size();i++){
            int u = i;
            int v = parent[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(adj,s,0,-1);
        return result;
    }
    int dfs(unordered_map<int,vector<int>> &adj,string &s,int u,int previous){

        int longest=0;
        int secondLongest=0;
        for(int &v:adj[u]){
            if(v==previous){
                continue;
            }
            int childLongestPath=dfs(adj,s,v,u);
            if(s[v]==s[u]){
                continue;
            }
            if(childLongestPath>secondLongest){
                secondLongest=childLongestPath;
            }
            if(longest<secondLongest){
                swap(longest,secondLongest);
            }
        }
        int koi_ek_bda_vala_path_niche_se=max(longest,secondLongest)+1;
        int only_curr_node=1;
        int only_niche_vala_parabola_ans=longest+secondLongest+1;
        result=max({result,koi_ek_bda_vala_path_niche_se,only_curr_node,only_niche_vala_parabola_ans});
        return max({only_curr_node,koi_ek_bda_vala_path_niche_se}); 


    }
};