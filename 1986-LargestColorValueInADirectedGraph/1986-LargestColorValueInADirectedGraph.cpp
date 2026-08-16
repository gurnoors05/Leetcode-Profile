// Last updated: 8/16/2026, 6:57:31 PM
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        vector<int> indegree(n,0);
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        vector<vector<int>> color_till_now(n,vector<int>(26,0));
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                color_till_now[i][colors[i]-'a']=1;
            }
        }
        int answer=0;
        int totalNodes=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            totalNodes++;
            answer=max(answer,color_till_now[u][colors[u]-'a']);
            for(auto& v:adj[u]){
                for(int i=0;i<26;i++){
                    color_till_now[v][i]=max(color_till_now[v][i],color_till_now[u][i]+(colors[v]-'a'==i));
                }
                indegree[v]--;
                if(indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        if(totalNodes < n)
            return -1;
        
        return answer;
    }
};