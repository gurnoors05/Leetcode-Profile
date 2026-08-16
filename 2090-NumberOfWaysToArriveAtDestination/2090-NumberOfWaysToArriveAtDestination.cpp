// Last updated: 8/16/2026, 6:56:54 PM
class Solution {
public:
    const int MOD=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto& r:roads){
            int u=r[0];
            int v=r[1];
            int dis=r[2];
            adj[u].push_back({v,dis});
            adj[v].push_back({u,dis});

        }
        pq.push({0,0});
        vector<long long> ways(n,0);
        ways[0]=1;
        vector<long long> result(n,LLONG_MAX);
        result[0]=0;
        while(!pq.empty()){
            long long dis=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            for(auto& p:adj[u]){
                int v=p.first;
                long long neighDis=p.second;
                if(v==u){
                    continue;
                }
                if(dis+neighDis<result[v]){
                    result[v]=dis+neighDis;
                    ways[v]=ways[u];
                    pq.push({dis+neighDis,v});
                }
                else if(dis+neighDis==result[v]){
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        return ways[n-1]%MOD;
    }
};