// Last updated: 8/16/2026, 6:52:23 PM
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<char,vector<pair<char,int>>> adj;
        for(int i=0;i<original.size();i++){
            char ch=original[i];
            adj[ch].push_back({changed[i],cost[i]});
        }
        vector<vector<long long>> costMatrix(26, vector<long long>(26, INT_MAX));
        for(int i=0;i<source.length();i++){
            char ch=source[i];
            dijkastra(ch,adj,costMatrix);
        }
        long long ans=0;
        for(int i=0;i<source.length();i++){
            if(source[i]==target[i]){
                continue;
            }
            if(costMatrix[source[i]-'a'][target[i]-'a']==INT_MAX){
                return -1;
            }
            ans+=costMatrix[source[i]-'a'][target[i]-'a'];
        }
        return ans;
    }
    void dijkastra(char& src,unordered_map<char,vector<pair<char,int>>> &adj,vector<vector<long long>> &costMatrix){
        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
        pq.push({0,src});
        while(!pq.empty()){
            int d=pq.top().first;
            char s=pq.top().second;
            pq.pop();
            for(auto& p:adj[s]){
                char neigh=p.first;
                int dis=p.second;
                if(costMatrix[src- 'a'][neigh - 'a'] > d + dis) {
                    costMatrix[src - 'a'][neigh - 'a'] = d + dis;
                    pq.push({d + dis, neigh});
                }
            }
        }
        return;
    }
};