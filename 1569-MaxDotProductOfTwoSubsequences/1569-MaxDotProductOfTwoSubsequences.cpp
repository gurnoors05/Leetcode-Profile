// Last updated: 8/16/2026, 7:00:43 PM
class Solution {
public:
    int dp[501][501];
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return solve(nums1,nums2,0,0);
    }
    int solve(vector<int>& nums1, vector<int>& nums2,int i,int j){
        int n=nums1.size();
        int m=nums2.size();
        if(i>=n || j>=m){
            return INT_MIN/2;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        // Because if you return 0, the recursion is allowed to "pick nothing", which violates the requirement that the subsequences must be non-empty.

        // For example:

        // nums1 = [-1]
        // nums2 = [1]

        // If the base case returns 0:

        // take = -1 + 0 = -1
        // skip1 = 0
        // skip2 = 0
        // The answer becomes 0, which is incorrect because you must choose at least one pair.
        // If the base case returns -∞:
        // take = -1 + (-∞)   // This reveals another subtle issue.
        // This leads to an important observation:
        // The take transition also needs adjustment.
        // If you write
        // take = product + solve(i+1, j+1);


        int product=nums1[i]*nums2[j];
        int take=max(product,product+solve(nums1,nums2,i+1,j+1));
        int skip1=solve(nums1,nums2,i+1,j);
        int skip2=solve(nums1,nums2,i,j+1);
        return dp[i][j]=max({take,skip1,skip2});
        
    }
};