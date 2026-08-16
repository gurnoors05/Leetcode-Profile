// Last updated: 8/16/2026, 7:10:45 PM
class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        unordered_map<int,vector<int>> adj;
        for(auto& edge:richer){
            int v=edge[0];
            int u=edge[1];
            adj[u].push_back(v);
        }
      
        vector<int> ans(n,-1);
        
        for(int i=0;i<n;i++){
            ans[i]=dfs(i,adj,quiet,ans);          
        }
        return ans;
    }
    int dfs(int person,unordered_map<int,vector<int>>& adj,vector<int>& quiet,vector<int> ans){
        if(ans[person]!=-1){
            return ans[person];
        }
        int best=person;
        for(auto& v:adj[person]){
            int new_candidate=dfs(v,adj,quiet,ans);
            if(quiet[new_candidate]<quiet[best]){
                best=new_candidate;
            }
            
        }
        return best;

    }
};