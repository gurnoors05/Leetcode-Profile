// Last updated: 8/16/2026, 7:05:58 PM
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n+1,0);
        vector<int> outdegree(n+1,0);
        if(trust.empty() && n==1)
            return 1;
        for(vector<int>& vec:trust){
           int u=vec[0];
           int v=vec[1];
           outdegree[u]++;
           indegree[v]++;
        }
        for(int i=0;i<=n;i++){
            if(outdegree[i]==0 && indegree[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};