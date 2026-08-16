// Last updated: 8/16/2026, 6:54:46 PM
class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rowSort=topoSort(rowConditions,k);
        vector<int> colSort=topoSort(colConditions,k);
        if(rowSort.empty() || colSort.empty()){
            return {};
        }
        vector<vector<int>> result(k,vector<int>(k,0));
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                if(rowSort[i]==colSort[j]){
                    result[i][j]=rowSort[i];
                }
            }
        }
        return result;
    }
    vector<int> topoSort(vector<vector<int>>& edges,int k){
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(k+1,0);
        for(auto& edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        int count=0;
        for(int i=1;i<k+1;i++){
            if(indegree[i]==0){
                q.push(i);
                count++;
            }
        }
        vector<int> order;
        while(!q.empty()){
            int u=q.front();
            order.push_back(u);
            q.pop();
            for(int &v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                    count++;
                }
            }
        }
        if(count!=k){
            return {};
        }
        return order;
    }
};