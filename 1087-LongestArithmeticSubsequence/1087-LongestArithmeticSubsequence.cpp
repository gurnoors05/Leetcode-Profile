// Last updated: 8/16/2026, 7:05:31 PM
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        // Using LIS approach
        int n=nums.size();
         if(n <= 2){
            return n;
         }
        vector<vector<int>> dp(n,vector<int>(1001,0)); //beacause if difference is -500, then wehave to add 501 extra to make it positive
        int result=0;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){ // ith index par sbse bda khtm hone vala LIS with diff diff
                int diff=nums[i]-nums[j]+500;
                dp[i][diff]=dp[j][diff]>0 ? dp[j][diff]+1 : 2;
                result=max(result,dp[i][diff]);
            }
        }
        return result;
    }
};