// Last updated: 8/16/2026, 7:03:10 PM
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);      
    }
    int solve(vector<int>& nums,int k){
     
        int l=0;
        int r=0;
        int n=nums.size();
        int count=0;
        int noOfSub=0;
        while(r<n){
            if(nums[r]%2!=0){
                count++;
            }
            if(count>k){
                while(count>k){
                    if(nums[l]%2!=0){
                        count--;
                    }
                    l++;
                }
            }
            if(count<=k){
                noOfSub+=(r-l+1);
            }
            r++;
        }
        return noOfSub;
    }
};