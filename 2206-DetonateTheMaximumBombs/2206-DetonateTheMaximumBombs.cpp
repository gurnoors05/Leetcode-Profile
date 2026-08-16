// Last updated: 8/16/2026, 6:56:14 PM
class Solution {
public:
    typedef long long LL;
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    continue;
                }
                LL x1=bombs[i][0];
                LL y1=bombs[i][1];
                LL r1=bombs[i][2];

                LL x2=bombs[j][0];
                LL y2=bombs[j][1];
                LL r2=bombs[j][2];
                LL distance=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                if(LL(r1*r1)>=distance){
                    adj[i].push_back(j);
                }
                
            }
        }
        int result=0;
        unordered_set<int> visited;
        for(int i=0;i<n;i++){
            dfs(visited,adj,i);
            int count=visited.size();
            result=max(result,count);
            visited.clear();
        }
        return result;
    }
    void dfs(unordered_set<int> &visited,unordered_map<int,vector<int>>& adj,int u){
        visited.insert(u);
        for(int &v : adj[u]) {
            if(visited.find(v) == visited.end()) { 
                dfs(visited, adj,v);
            }
        }
    }

};