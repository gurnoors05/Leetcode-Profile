// Last updated: 8/16/2026, 6:53:21 PM
class Solution {
public:
    const int LargeValue=2e9;
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        long long currShortestDis=dijkastra(n,edges,source,destination);
        if(currShortestDis<target){
            return {};
        }
        bool matchedTarget = (currShortestDis==target);
        // for(auto& edge:edges){
        //     if(edge[2]==-1){
        //         edge[2]=LargeValue;
        //     }
        // }
        for(auto& edge:edges){
            if(edge[2]==-1){
                edge[2]=(matchedTarget==true)?LargeValue:1;
            
                if(matchedTarget!=true){
                    long long newShortestDis=dijkastra(n,edges,source,destination);
                    if(newShortestDis<=target){
                        matchedTarget=true;
                        edge[2]+=(target-newShortestDis);
                    }
                }
            }
        }
        if(matchedTarget==false){
            return {};
        }
        return edges;
    }
    long long dijkastra(int n,vector<vector<int>>& edges,int src,int dst){
        // without -1
        unordered_map<long long,vector<pair<long long,long long>>> adj;
        for(auto& edge:edges){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            if(edge[2]!=-1){
                adj[u].push_back({v, w});
                adj[v].push_back({u, w});
            }
        }
       vector<long long> result(n, LLONG_MAX);

        result[src]=0;
        priority_queue<pair<long, long>, vector<pair<long,long>> , greater<pair<long, long>>> pq;
        pq.push({0,src});
        while(!pq.empty()){
            long long  dis=pq.top().first;
            long long node=pq.top().second;
            pq.pop();
            for(auto &p:adj[node]){
                int v=p.first;
                int neighDis=p.second;
                if(result[v]>dis+neighDis){
                    result[v]=dis+neighDis;
                    pq.push({dis+neighDis,v});
                }
            }
        }
        return result[dst];
    }
};;