// Last updated: 8/16/2026, 7:02:49 PM
class Solution {
public:
    int dp[301][301];
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        memset(dp,-1,sizeof(dp));
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==1){
                    int ans=solve(matrix,m,n,i,j);
                    count+=ans;
                }
            }
        }
        return count;
    }
    int solve(vector<vector<int>>& matrix,int m,int n,int i,int j){
        if(i==m || j==n){
            return 0;
        }
        if(matrix[i][j]==0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int right=solve(matrix,m,n,i,j+1);
        int down=solve(matrix,m,n,i+1,j);
        int diag=solve(matrix,m,n,i+1,j+1);
        int result=1+min(right,min(down,diag));
        return dp[i][j]=result;
    }
};