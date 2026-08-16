// Last updated: 8/16/2026, 7:06:50 PM
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // subarrays with sum == 2 => suabarrys with sum <=2 - subarrays with sum <=1
        return solve(nums,goal)-solve(nums,goal-1);
    }
    int solve(vector<int>& nums,int goal){
        if(goal<0){
            return 0;
        }
        int l=0;
        int r=0;
        int currSum=0;
        int count=0;
        int count2=0;
        int n=nums.size();
        while(r<n){
            currSum+=nums[r];
            if(currSum>goal){
                while(currSum>goal){
                    currSum-=nums[l];
                    l++;
                }
            }
            if(currSum<=goal){
                count+=(r-l+1);
            }
           
            r++;
        }
        return count;
    }
};