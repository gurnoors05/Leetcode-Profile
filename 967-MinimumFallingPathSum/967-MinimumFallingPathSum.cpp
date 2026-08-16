// Last updated: 8/16/2026, 7:06:47 PM
class Solution {
public:
    // int dp[101][101];
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> ans(n,vector<int>(n));
        for(int i=0;i<n;i++){
            ans[0][i]=matrix[0][i];
        }
        for(int row=1;row<n;row++){
            for(int col=0;col<n;col++){
                int a=INT_MAX;
                int b=INT_MAX;
                int c=INT_MAX;
                if(col-1>=0){
                    a=ans[row-1][col-1];
                }
                if(col+1<n){
                    b=ans[row-1][col+1];
                }
                c=ans[row-1][col];
                ans[row][col]=matrix[row][col]+min(a,min(b,c));
            }
        }
        int lastrow=n-1;
        int result=INT_MAX;
        for(int col=0;col<n;col++){
            result=min(result,ans[lastrow][col]);
        }
        return result;





        // int n=matrix.size();
        // int m=matrix[0].size();
        // int result = INT_MAX;
        // memset(dp,-1,sizeof(dp));
        // for(int j=0;j<m;j++){
        //     result=min(result,solve(matrix,n,m,0,j));
        // }
        // return result;
    }
    // int solve(vector<vector<int>>& matrix,int n,int m,int i,int j){
    //     // Out of bounds
    //     if (i == n - 1) return matrix[i][j];
    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }
    //     int sum=matrix[i][j];
    //     int result=INT_MAX;
    //     if(i+1<n && j-1>=0){
    //         result=min(result,sum+solve(matrix,n,m,i+1,j-1));
    //     }
    //     if(i+1<n){
    //         result=min(result,sum+solve(matrix,n,m,i+1,j));
    //     }
    //     if(i+1<n && j+1<n){
    //        result=min(result,sum+solve(matrix,n,m,i+1,j+1));
    //     }
    //     return dp[i][j]=result;
       
    // }
};