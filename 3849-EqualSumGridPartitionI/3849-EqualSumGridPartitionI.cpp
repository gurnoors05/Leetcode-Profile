// Last updated: 8/16/2026, 6:50:28 PM
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        long long total=0;
        vector<long long> rowSum(n,0);
        vector<long long> colSum(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                total+=grid[i][j];
                rowSum[i]+=grid[i][j];
                colSum[j]+=grid[i][j];
            }
        }
        long long upper=0;
        for(int i=0;i<n;i++){
            upper+=rowSum[i];
            if(upper==(total-upper)){
                return true;
            }
        }
        long long right=0;
        for(int j=0;j<m;j++){
            right+=colSum[j];
            if(right==(total-right)){
                return true;
            }
        }
        return false;
    }
};