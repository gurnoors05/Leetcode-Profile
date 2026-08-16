// Last updated: 8/16/2026, 6:56:42 PM
class Solution {
public:
    vector<long long> dp;
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(),rides.end());
        dp.assign(rides.size(),-1);
        return solve(n,rides,0);
    }
    long long solve(int n,vector<vector<int>>& rides,int i){
        if(i>=rides.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        long long skip=solve(n,rides,i+1);
        int nextRide=findNext(n,rides,rides[i][1],i+1);
        long long take=(long long)(rides[i][1]-rides[i][0]+rides[i][2]) +solve(n,rides,nextRide);
        return dp[i]=max(take,skip);
    }
    int findNext(int n,vector<vector<int>>& nums,int target,int left){
        int right=nums.size();
        while(left<right){
            int mid=left+(right-left)/2;
            if(nums[mid][0]<target){
                left=mid+1;

            }
            else{
                right=mid;
            }
        }
        return left;
    }
};