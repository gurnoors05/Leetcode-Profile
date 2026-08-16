// Last updated: 8/16/2026, 7:10:48 PM
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        int m=graph[0].size();
        int finalMask=(1<<n)-1;
        set<pair<int,int>> st;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            int mask=(1<<i);
            q.push({i,mask});
            st.insert({i,mask});
        }
        int level=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto p=q.front();
                q.pop();
                int u=p.first;
                int currMask=p.second;
                if(finalMask==currMask){
                    return level;
                }
                for(auto& neigh:graph[u]){
                    int neighmask=1<<neigh;
                    int newmask=currMask|neighmask;
                    if(st.find({neigh,newmask})==st.end()){
                        st.insert({neigh,newmask});
                        q.push({neigh,newmask});
                    }
                }
            }
            level++;
        }
        return -1;
        
        
    }
};