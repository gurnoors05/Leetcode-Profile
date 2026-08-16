// Last updated: 8/16/2026, 7:00:21 PM
class Solution {
public:
    // Give MLE
    // vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
    //     unordered_map<int,vector<int>> adj;
    //     for(int i=0;i<edges.size();i++){
    //         int u=edges[i][0];
    //         int v=edges[i][1];
    //         adj[u].push_back(v);
    //         adj[v].push_back(u);
    //     }
    //      vector<int> result(n,0);
    //     dfs(adj,labels,0,-1,n,result);
    //     return result;
    // }
    // vector<int> dfs(unordered_map<int,vector<int>> &adj,string labels,int u,int previous,int n,vector<int> &result){
    //     int label_u=labels[u]-'a';
    //     vector<int> myLabel(26,0);
    //     myLabel[label_u]=1;
    //     for(auto& v:adj[u]){
    //         if(v==previous){
    //             continue;
    //         }
    //         vector<int> childFreq(26,0);
    //         childFreq=dfs(adj,labels,v,u,n,result);
    //         for(int i=0;i<26;i++){
    //             myLabel[i]+=childFreq[i];
    //         }
    //     }
    //     result[u]=myLabel[label_u];
    //     return myLabel;
    // }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string &labels) {
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> result(n,0);
        vector<int> count(26,0);
        dfs(adj,labels,0,-1,count,result);
        return result;
    }
    void dfs(unordered_map<int,vector<int>> &adj,string &labels,int u,int previous,vector<int> &count,vector<int> &result){
        char label_u=labels[u];
        int count_before_exploring_my_subtree=count[label_u-'a'];

        count[label_u-'a']+=1;
        for(auto& v:adj[u]){
            if(previous==v){
                continue;
            }
            dfs(adj,labels,v,u,count,result);
        }
        int count_after_exploring_my_subtree=count[label_u-'a'];
        result[u]=count_after_exploring_my_subtree-count_before_exploring_my_subtree;
    }

};