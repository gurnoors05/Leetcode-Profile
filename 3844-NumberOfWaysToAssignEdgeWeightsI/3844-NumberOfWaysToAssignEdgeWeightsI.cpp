// Last updated: 8/16/2026, 6:50:31 PM
class Solution {
public:
    int maxDepth = 0;
      static constexpr long long MOD = 1e9 + 7;

    long long power(long long base, long long exponent) {
        if (exponent == 0)
            return 1;

        long long half = power(base, exponent / 2);

        long long result = (half * half) % MOD;

        if (exponent % 2 == 1) {
            result = (result * base) % MOD;
        }

        return result;
    }


    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size();
        unordered_map<int,vector<int>> mp;
        int maxNode=0;
        for(auto& edge:edges){
            int u=edge[0];
            int v=edge[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
            maxNode = max({maxNode, u, v});
        }
        vector<bool> visited(maxNode+1,false);
        int depth=0;
        visited[1]=true;
        solve(mp,1,visited,depth);
        return power(2,maxDepth-1); 
    }
    void solve(unordered_map<int,vector<int>>& mp,int u,vector<bool> &visited,int depth){
        maxDepth=max(depth,maxDepth);
        for(auto& neigh:mp[u]){
            if(visited[neigh]==false){
                visited[neigh]=true;
                solve(mp,neigh,visited,depth+1);
            }
        }
    }
};