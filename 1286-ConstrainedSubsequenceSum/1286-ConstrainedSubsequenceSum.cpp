// Last updated: 8/16/2026, 7:03:55 PM
class Solution {
public:
    // Using dp + memo --- But it will give TLE
    // int constrainedSubsetSum(vector<int>& nums, int k) {
    //     int n=nums.size();
    //     int val= solve(nums,k,0,n,-1);
    //     if(val==0){
    //         val=*max_element(begin(nums),end(nums));
    //     }
    //     return val;
    // }
    // int solve(vector<int>& nums,int k,int i,int n,int previous){
    //     if(i>=n){
    //         return 0;
    //     }
    //     int take=0;
    //     if(previous==-1 || i-previous<=k){
    //         take=nums[i]+solve(nums,k,i+1,n,i);
    //     }
    //     int not_take=solve(nums,k,i+1,n,previous);
    //     int result=max(take,not_take);
    //     return result;
    // }

    // Using Bottom Up - TLE
    // int constrainedSubsetSum(vector<int>& nums, int k) {
    //    vector<int> dp(nums.size(),0);
    //    for(int i=0;i<nums.size();i++){
    //         dp[i]=nums[i];
    //    }
    //    int maxi=dp[0];
    //    for(int i=1;i<nums.size();i++){
    //     for(int j=i-1;j>=0 && i-j<=k;j--){
    //         dp[i]=max(dp[i],nums[i]+dp[j]);
    //         maxi=max(maxi,dp[i]);
    //     }
    //    }
    //    return maxi;
    // }


    //Using Prriority Queue -- Max heap
    // Will store Largest and its index on top
    // If index is between the range i.e i-indx<=k then we got the maximum sum till index i and will add nums[i] into it
    // int constrainedSubsetSum(vector<int>& nums, int k){
    //     priority_queue< pair<int,int>, vector<pair<int,int>>> q;
    //     q.push({nums[0],0});
    //     vector<int> dp(nums.size(),0);
    //    for(int i=0;i<nums.size();i++){
    //         dp[i]=nums[i];
    //    }
    //     int maxi=dp[0];
    //     for(int i=1;i<nums.size();i++){
    //         while(!q.empty() && i-q.top().second>k){ // Jab Tak range mein nhi ata, tab tk pop krte rho
    //             q.pop();
    //         }
    //         dp[i]=max(dp[i],nums[i]+q.top().first);
    //         q.push({dp[i],i});
    //         maxi=max(maxi,dp[i]);
    //     }
    //     return maxi;
    // }

    // Using Monotonic Decreasing Dequeue
    int constrainedSubsetSum(vector<int>& nums, int k){
        deque<int> dq;
        vector<int> dp(nums);
        int maxi=dp[0];
        for(int i=0;i<nums.size();i++){
            while(!dq.empty() && i-dq.front()>k){
                dq.pop_front();
            }
            if(!dq.empty()){
                dp[i]=max(dp[i],nums[i]+dp[dq.front()]);
            }
            while(!dq.empty() && dp[i]>dp[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
            maxi=max(maxi,dp[i]);
        }

        return maxi;
    }
};