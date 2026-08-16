// Last updated: 8/16/2026, 6:52:54 PM
class Solution {
public:
    int M=12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        long long suffixproduct=1;
        vector<vector<int>> ans(n,vector<int>(m));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                ans[i][j]=suffixproduct;
                suffixproduct=(suffixproduct*grid[i][j])%M;
            }
        }
        long long prefixProduct=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]=(ans[i][j]*prefixProduct)%M;
                prefixProduct=(prefixProduct*grid[i][j])%M;
            }
           
        }
         return ans;
    }
        
        
};