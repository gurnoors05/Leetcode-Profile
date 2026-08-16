// Last updated: 8/16/2026, 6:57:11 PM
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int row=findMax(mat,mid);
            int left=mid-1>=0?mat[row][mid-1]:INT_MIN;
            int right=mid+1<n?mat[row][mid+1]:INT_MIN;
            if (mat[row][mid] > left && mat[row][mid] > right) {
                  return {row, mid};
            } 
            else if(mat[row][mid]<left){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return {-1,-1};
    }
    int findMax(vector<vector<int>>& mat,int col){
        int prev=-1;
        int ans=-1;
        for(int i=0;i<mat.size();i++){
            if(mat[i][col]>prev){
                ans=i;
                prev=mat[i][col];
            }
        }
        return ans;
    }
};