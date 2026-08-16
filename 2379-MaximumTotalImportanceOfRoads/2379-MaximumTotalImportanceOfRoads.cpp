// Last updated: 8/16/2026, 6:55:13 PM
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> indegree(n,0);
        for(auto& edge:roads){
            int u=edge[0];
            int v=edge[1];
            indegree[u]++;
            indegree[v]++;
        }
        sort(begin(indegree),end(indegree));
        long long value=1;
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=(indegree[i]*value);
            value++;
        }
        return sum;

    }
};