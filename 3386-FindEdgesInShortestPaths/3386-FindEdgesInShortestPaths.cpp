// Last updated: 8/16/2026, 6:51:48 PM
class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<pair<long,long>>> adj;
        for(auto& edge:edges){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int> fromSrc=dijkastra(adj,0,n);
        vector<int> fromDest=dijkastra(adj,n-1,n);
        vector<bool> result(edges.size(),false);
        for(int i = 0; i < edges.size(); i++) {    
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];  
            long long distFromSrc  = fromSrc[u]; //x
            long long distFromDest = fromDest[v]; //y
            if(distFromSrc + w + distFromDest==fromSrc[n-1]){
                result[i]=true;
            }

            distFromSrc  = fromSrc[v]; //x
            distFromDest = fromDest[u]; //y
            if(distFromSrc + w + distFromDest==fromSrc[n-1]){
                result[i]=true;
            }
        }
        return result;
    }
    vector<int> dijkastra(unordered_map<int,vector<pair<long,long>>> &adj,int src,int n){
        vector<bool> visited(n,false);
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        priority_queue<pair<long,long>, vector<pair<long,long>>, greater<pair<long,long>>> pq;
        pq.push({0,src});
        while(!pq.empty()){
            long long dis=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            if(visited[u]==true){
                continue;
            }
            for(auto& p:adj[u]){
                int v=p.first;
                long long d=p.second;
                if(dis+d < dist[v]){
                    dist[v] = dis+d;
                    pq.push({dis+d,v});
                }
            }
            visited[u]=true;
        }
        return dist;
    }
};