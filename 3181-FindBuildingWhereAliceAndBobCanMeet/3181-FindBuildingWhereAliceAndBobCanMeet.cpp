// Last updated: 8/16/2026, 6:52:47 PM
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n=heights.size();
        int totalQueries=queries.size();
        // to store queries ans
        vector<int> ans(totalQueries,-1);
        // unoredred map - Max query index -> max Height, query no
        unordered_map<int, vector<pair<int,int>>> mp;
        // min heap : maxHeight,query no
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // 1 : answering basic queries and creating map for remaining
        for(int q=0;q<totalQueries;q++){
            int i=queries[q][0];
            int j=queries[q][1];
            if(i<j && heights[i]<heights[j]){
                ans[q]=j;
            }
            else if(i>j && heights[i]>heights[j]){
                ans[q]=i;
            }
            else if(i==j){
                ans[q]=i;
            }
            else{
                mp[max(i,j)].push_back({max(heights[i],heights[j]),q});
            }
        }
        // 2: use priority queue to handle remaining queries
        for(int i=0;i<n;i++){
            // check which queries can be answered with index i
            while(!pq.empty() && pq.top().first<heights[i]){
                ans[pq.top().second]=i;
                pq.pop();
            }
            for(auto &it:mp[i]){
                pq.push(it);
            }
        }
        return ans;
    }
};