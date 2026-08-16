// Last updated: 8/16/2026, 7:01:47 PM
class Solution {
public:
    int dp[1001];
    int maxJumps(vector<int>& arr, int d) {
        int n=arr.size();
        int maxi=INT_MIN;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            maxi=max(maxi,solve(arr,d,i));
        }
        return maxi;
    }
    int solve(vector<int>& nums, int d,int i){
        int n=nums.size();
        if(i<0 || i>=nums.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int result=1;
        // left
        for(int j=i-1;j>=max(0,i-d);j--){
            if(nums[j]>=nums[i]){
                break;
            }
            result=max(result,1+solve(nums,d,j));
        }
        // right
        for(int j=i+1;j<=min(n-1,i+d);j++){
            if(nums[j]>=nums[i]){
                break;
            }
            result=max(result,1+solve(nums,d,j));
        }
        return dp[i]=result;
    }
};