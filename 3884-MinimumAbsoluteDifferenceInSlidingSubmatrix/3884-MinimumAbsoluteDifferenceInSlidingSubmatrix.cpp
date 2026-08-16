// Last updated: 8/16/2026, 6:50:24 PM
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> ans(m-k+1,vector<int>(n-k+1,0));
        for(int i=0;i<=m-k;i++){
            for(int j=0;j<=n-k;j++){
                set<int> st;
                for(int r=i;r<=i+k-1;r++){
                    for(int c=j;c<=j+k-1;c++){
                        st.insert(grid[r][c]);
                    }
                }
                if(st.size()==1){
                    continue;
                }
                int minAbsDiff = INT_MAX;
                auto prev = st.begin();
                auto curr = next(prev);
                
                while (curr != st.end()) {
                    minAbsDiff = min(minAbsDiff, *curr - *prev);
                    prev = curr;
                    curr++;
                }
                ans[i][j]=minAbsDiff;
            }
          
        }
        return ans;
    }
};