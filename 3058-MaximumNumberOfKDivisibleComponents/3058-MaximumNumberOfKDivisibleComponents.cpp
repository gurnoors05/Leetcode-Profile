// Last updated: 8/16/2026, 6:52:50 PM
class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,vector<int>& values, int k) {
        vector<vector<int>> adj(n+1);
        for(auto& e:edges){
            int i=e[0],j=e[1];
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
        int ans=0;
        dfs(0,-1,ans,adj,values,k);
        return ans;
    }
    long long dfs(int node,int parent,int& ans,vector<vector<int>>& adj,vector<int>& values,int& k){
        long long sum=values[node];
        for(auto it:adj[node]){
            if(it!=parent){
                sum+=dfs(it,node,ans,adj,values,k);
            }
        }
        if(sum%k==0){
            ans++;
            return 0;
        }
        return sum;
    }

};