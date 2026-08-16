// Last updated: 8/16/2026, 7:02:04 PM
class Solution {
public:
    // int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // using dijkastra
        // dijakastra find shortest path from one source to every other vertex
        // In this ques we have to make every vertex as source one by one
    //     unordered_map<int,vector<pair<int,int>>> adj;
    //     for(vector<int> &vec:edges){
    //         int u=vec[0];
    //         int v=vec[1];
    //         int w=vec[2];
    //         adj[u].push_back({v,w});
    //         adj[v].push_back({u,w});
    //     }
        
    //     vector<vector<int>> result(n,vector<int>(n,INT_MAX));
    //     // dis of each vertex to itself will be zero;
    //     for(int i=0;i<n;i++){
    //         result[i][i]=0;
    //     }
    //     for(int i=0;i<n;i++){
    //         dijkastra(n,adj,result[i],i); // source is i, and we are sending ith row of result to fill
    //     }
    //     return mincity(n,result,distanceThreshold);
    // }
    // int mincity(int n,vector<vector<int>>& result,int thresh){
    //     int min=INT_MAX;
    //     int resultcity=-1;
    //     for(int i=0;i<n;i++){
    //         int rowmin=0;
    //         for(int j=0;j<n;j++){
    //             if(i!=j && result[i][j]<=thresh){
    //                 rowmin++;
    //             }
    //         }
    //         if(rowmin<=min){
    //             min=rowmin;
    //             resultcity=i;
    //         }
    //     }
    //     return resultcity;
    // }
    // void dijkastra(int n,unordered_map<int,vector<pair<int,int>>>& adj,vector<int>& result,int source){
    //     priority_queue<pair<int,int> , vector<pair<int,int>>,greater<pair<int,int>>> q;
    //     fill(result.begin(),result.end(),INT_MAX);
    //     result[source]=0;
    //     q.push({0,source});
    //     while(!q.empty()){
    //         int dis=q.top().first;
    //         int node=q.top().second;
    //         q.pop();
    //         for(pair<int,int> &p:adj[node]){
    //             int adjNode=p.first;
    //             int adjDis=p.second;
    //             if(dis+adjDis<result[adjNode]){
    //                 result[adjNode]=dis+adjDis;
    //                 q.push({dis+adjDis,adjNode});
    //             }
    //         }
    //     }




        // USING floyd warshal       
    //     vector<vector<int>> result(n,vector<int>(n,INT_MAX));
    //     for(int i=0;i<n;i++){
    //         result[i][i]=0;
    //     }
    //     for(vector<int> &vec:edges){
    //         int u=vec[0];
    //         int v=vec[1];
    //         int w=vec[2];
    //        result[u][v]=w;
    //        result[v][u]=w;
    //     }
                       
    //     floydWarshall(n,result);
    //     return mincity(n,result,distanceThreshold);
    // }
    // void floydWarshall(int n,vector<vector<int>>& result){
    //     for(int k=0;k<n;k++){
    //         for(int i=0;i<n;i++){
    //             for(int j=0;j<n;j++){
    //                 if (result[i][k] != INT_MAX && result[k][j] != INT_MAX) {
    //                     result[i][j] = min(result[i][j], result[i][k] + result[k][j]);
    //                 }
    //             }
    //         }
    //     }
    // }
    // int mincity(int n,vector<vector<int>>& result,int thresh){
    //     int min=INT_MAX;
    //     int resultcity=-1;
    //     for(int i=0;i<n;i++){
    //         int rowmin=0;
    //         for(int j=0;j<n;j++){
    //             if(i!=j && result[i][j]<=thresh){
    //                 rowmin++;
    //             }
    //         }
    //         if(rowmin<=min){
    //             min=rowmin;
    //             resultcity=i;
    //         }
    //     }
    //     return resultcity;
    
    // }
     int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // using belmann ford
        // belman ford find shortest path from one source to every other vertex
        // In this ques we have to make every vertex as source one by one
        
        
        vector<vector<int>> result(n,vector<int>(n,INT_MAX));
        // dis of each vertex to itself will be zero;
        for(int i=0;i<n;i++){
            result[i][i]=0;
        }
        for(int i=0;i<n;i++){
            belmanFord(n,edges,result[i],i); // source is i, and we are sending ith row of result to fill
        }
        return mincity(n,result,distanceThreshold);
    }
    int mincity(int n,vector<vector<int>>& result,int thresh){
        int mini=INT_MAX;
        int resultcity=-1;
        for(int i=0;i<n;i++){
            int rowmin=0;
            for(int j=0;j<n;j++){
                if(i!=j && result[i][j]<=thresh){
                    rowmin++;
                }
            }
            if(rowmin<=mini){
                mini=rowmin;
                resultcity=i;
            }
        }
        return resultcity;
    }
    void belmanFord(int n,vector<vector<int>>& edges,vector<int>& result,int source){
        fill(result.begin(),result.end(),INT_MAX);
        result[source]=0;
        for(int i=0;i<n-1;i++){

          for(auto& edge:edges){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            if(result[u]!=INT_MAX && result[u]+w<result[v]){
                result[v]=result[u]+w;
            }
            if (result[v] != INT_MAX && result[v] + w < result[u]) {
                result[u] = result[v] + w;
            }
          }
        }
   
    }
};