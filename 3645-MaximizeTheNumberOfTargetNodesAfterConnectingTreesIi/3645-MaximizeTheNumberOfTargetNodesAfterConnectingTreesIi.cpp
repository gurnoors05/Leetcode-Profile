// Last updated: 8/16/2026, 6:50:47 PM
class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size()+1;
        int m=edges2.size()+1;
        unordered_map<int,vector<int>> adj1=findAdj(edges1);
        unordered_map<int,vector<int>> adj2=findAdj(edges2);
        vector<int> numberAssigned1(n,-1);
        int countof0thNodes1=0;
        int countof1thNodes1=0;
        numberAssigned1[0]=0;
        dfs(0,adj1,-1,numberAssigned1,countof0thNodes1,countof1thNodes1);

        vector<int> numberAssigned2(m,-1);
        int countof0thNodes2=0;
        int countof1thNodes2=0;
        numberAssigned2[0]=0;
        dfs(0,adj2,-1,numberAssigned2,countof0thNodes2,countof1thNodes2);

        int maxReachToTree2=max(countof0thNodes2,countof1thNodes2);
        vector<int> result(n);
        for(int i=0;i<n;i++){
            int totalReachable;
            if(numberAssigned1[i]==0){
                totalReachable=countof0thNodes1+maxReachToTree2;
                result[i]=(totalReachable);
            }
            else{
                totalReachable=countof1thNodes1+maxReachToTree2;
                result[i]=(totalReachable);
            }
        }
        return result;

    }
    unordered_map<int, vector<int>> findAdj(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return adj;
    }
    void dfs(int curr, unordered_map<int, vector<int>>& adj, int parent, vector<int>& mark, 
        int &zeroMarkedCount, int& oneMarkedCount) {

        if(mark[curr] == 0) {
            zeroMarkedCount++;
        } else {
            oneMarkedCount++;
        }

        for(auto &ngbr : adj[curr]) {
            if(ngbr != parent) {
                mark[ngbr] = (mark[curr] == 0) ? 1 : 0; //alternate marking
                dfs(ngbr, adj, curr, mark, zeroMarkedCount, oneMarkedCount);
            }
        }
    }
};