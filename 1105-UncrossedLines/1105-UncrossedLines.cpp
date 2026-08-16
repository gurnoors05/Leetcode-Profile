// Last updated: 8/16/2026, 7:05:23 PM
class Solution {
public:
    int dp[501][501];
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return solve(nums1,nums2,0,0);
    }
    int solve(vector<int>& nums1, vector<int>& nums2,int i,int j){
        if(i==nums1.size() || j==nums2.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int take=0;
        int skip=0;
        if(nums1[i]==nums2[j]){
            take=1+solve(nums1,nums2,i+1,j+1);
        }
        skip=max(solve(nums1,nums2,i+1,j),solve(nums1,nums2,i,j+1));
        return dp[i][j]=max(take,skip);
    }
};