// Last updated: 8/16/2026, 6:59:25 PM
class Solution {
public:
    unordered_map<int,unordered_set<int>> adj;
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            adj[u].insert(v);
            adj[v].insert(u);
        }
        int maxRank=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int i_neigh=adj[i].size();
                int j_neigh=adj[j].size();
                int rank= i_neigh+j_neigh;
                if(adj[i].find(j)!=adj[i].end()){
                    rank-=1;
                }
                maxRank=max(maxRank,rank);
            }
        }
        return maxRank;
    }
};