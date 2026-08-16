// Last updated: 8/16/2026, 6:52:46 PM
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n,0);
        // if(edges.empty()){
        //     return -1;
        // }
        for(auto& edge:edges){
            indegree[edge[1]]++;
        }
        int count=0;
        int element=-1;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                element=i;
                count++;
                if(count>1){
                    return -1;
                }
            }
            
        }
        return element;
    }
};