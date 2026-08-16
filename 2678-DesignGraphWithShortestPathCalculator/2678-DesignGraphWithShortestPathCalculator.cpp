// Last updated: 8/16/2026, 6:53:41 PM
class Graph {
public:
    unordered_map<int,vector<pair<int,int>>> adj;
    vector<int> result;
    int N;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    // min heap
    Graph(int n, vector<vector<int>>& edges) {
        N=n;
        for(auto& edge:edges){
            int u=edge[0];
            int v=edge[1];
            int dis=edge[2];
            adj[u].push_back({v,dis});
        }
    }
    
    void addEdge(vector<int> edge) {
        int u=edge[0];
        int v=edge[1];
        int dis=edge[2];
        adj[u].push_back({v,dis});
    }
    
    int shortestPath(int node1, int node2) {
        vector<int> result(N,INT_MAX);
        result[node1]=0;
        pq.push({0,node1});
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto& neigh:adj[node]){
                int v=neigh.first;
                int d=neigh.second;
                if(dis+d<result[v]){
                    result[v]=d+dis;
                    pq.push({d+dis,v});
                }
            }
        }
        return result[node2]==INT_MAX?-1:result[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */