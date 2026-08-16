// Last updated: 8/16/2026, 6:51:21 PM
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> currSumX(n,vector<int>(m,0));
        vector<vector<int>> currSumY(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='X'){
                    currSumX[i][j]++;
                }
                else if(grid[i][j]=='Y'){
                    currSumY[i][j]++;
                }
                if(i-1>=0){
                    currSumX[i][j]+=currSumX[i-1][j];
                    currSumY[i][j]+=currSumY[i-1][j];
                }
                if(j-1>=0){
                    currSumX[i][j]+=currSumX[i][j-1];
                    currSumY[i][j]+=currSumY[i][j-1];
                }
                if(i-1>=0 && j-1>=0){
                    currSumX[i][j]-=currSumX[i-1][j-1];
                    currSumY[i][j]-=currSumY[i-1][j-1];
                }
                if(currSumX[i][j]==currSumY[i][j] && currSumX[i][j] > 0){
                    count++;
                }
            }
            
        }
        return count;
    }
};