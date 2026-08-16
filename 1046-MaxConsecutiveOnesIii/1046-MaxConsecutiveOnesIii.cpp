// Last updated: 8/16/2026, 7:05:57 PM
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        return solve(nums,k);
    }
    int solve(vector<int>& nums,int k){
        // int l=0;
        // int r=0;
        // int ans=INT_MIN;
        // int n=nums.size();
        // int zeros=0;
        // while(r<n){
        //     if(nums[r]==0){
        //         zeros++;
        //     }
        //         while(zeros>k){
        //             if(nums[l]==0){
        //                 zeros--;
        //             }
        //             l++;
        //         }
        //         if(zeros<=k){
        //             int length=r-l+1;
        //             ans=max(ans,length);
        //         }
            
        //     r++;
        // }
        // return ans;



        // More Optimised
        int l=0;
        int r=0;
        int n=nums.size();
        int zeros=0;
        int ans=INT_MIN;
        while(r<n){
            if(nums[r]==0){
                zeros++;
            }
            if(zeros>k){
                if(nums[l]==0){
                    zeros--;
                }
                l++;
            }
            if(zeros<=k){
                int length=r-l+1;
                ans=max(ans,length);
            }
            r++;
        }
        return ans;
    }
};