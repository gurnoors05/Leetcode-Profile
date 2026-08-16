// Last updated: 8/16/2026, 6:50:27 PM
class Solution {
public:
    long long total=0;
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                total+=grid[i][j];
            }
        }
        if(checkHorizotalCut(grid)){
            return true;
        }
        reverse(grid.begin(),grid.end());
        if(checkHorizotalCut(grid)){
            return true;
        }
        vector<vector<int>> transpose(m,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                transpose[j][i]=grid[i][j];
            }
        }
        if(checkHorizotalCut(transpose)){
            return true;
        }
        reverse(transpose.begin(),transpose.end());
        if(checkHorizotalCut(transpose)){
            return true;
        }
        return false;
    }
    bool checkHorizotalCut(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        long long top=0;
        set<long long> st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                st.insert(grid[i][j]);
                top+=grid[i][j];
            }
            long long bottom = (total - top);
            long long diff = top - bottom;

            if (diff == 0) return true;

            if (diff == (long long)grid[0][0])   return true;
            if (diff == (long long)grid[0][m-1]) return true;
            if (diff == (long long)grid[i][0]) return true;

            if(i > 0 && m > 1 && st.count(diff)) {
                return true;
            }
        }
        return false;
    }
};