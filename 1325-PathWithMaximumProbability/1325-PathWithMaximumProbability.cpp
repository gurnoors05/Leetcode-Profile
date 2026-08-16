// Last updated: 8/16/2026, 7:03:31 PM
class Solution {
public:
    // Using dijkastra for undirected weighted graph and also using priority queue
    // maximizing probability to each node from start node
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int,vector<pair<int,double>>> adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double prob=succProb[i];
            adj[u].push_back({v,prob});
            adj[v].push_back({u,prob});
        }
        priority_queue<pair<double,int>> pq;
        pq.push({1,start_node});
        vector<double> result(n,0);
        result[start_node]=1;
        while(!pq.empty()){
            int currNode=pq.top().second;
            double currProb=pq.top().first;
            pq.pop();
            for(auto& neigh:adj[currNode]){
                if(result[neigh.first]<currProb*neigh.second){
                    result[neigh.first]=currProb*neigh.second;
                    pq.push({currProb*neigh.second,neigh.first});
                }
            }
        }
        return result[end_node];


    }
};