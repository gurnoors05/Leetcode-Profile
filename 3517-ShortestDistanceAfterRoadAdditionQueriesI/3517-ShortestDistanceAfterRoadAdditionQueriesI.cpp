// Last updated: 8/16/2026, 6:51:13 PM
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> result;
        unordered_map<int,vector<pair<int,int>>> adj;
        for(int i=0;i<n-1;i++){
            adj[i].push_back({i+1,1});
        }
        for(auto& edge:queries){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back({v,1});
            int newDis=dijkastra(adj,n);
            result.push_back(newDis);
        }
        return result;
    }
    int dijkastra(unordered_map<int,vector<pair<int,int>>>& adj,int n){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> result(n,INT_MAX);
        pq.push({0,0});
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(node==n-1){
                return result[n-1];
            }
            if(dis>result[node]){
                continue;
            }
            for(auto& p:adj[node]){
                int neigh=p.first;
                int neighDis=p.second;
                if(dis+neighDis<result[neigh]){
                    result[neigh]=dis+neighDis;
                    pq.push({dis+neighDis,neigh});
                }
            }
        }
        return result[n-1];
    }
};