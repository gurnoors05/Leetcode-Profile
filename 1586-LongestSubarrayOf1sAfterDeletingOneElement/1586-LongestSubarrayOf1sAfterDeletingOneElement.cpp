// Last updated: 8/16/2026, 7:00:33 PM
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        return solve(nums);

    }
    int solve(vector<int>& nums){
        int l=0;
        int r=0;
        int n=nums.size();
        int countZeros=0;
        int max_length=INT_MIN;
        while(r<n){
            if(nums[r]==0){
                countZeros++;
            }
            if(countZeros>1){
                while(countZeros>1){
                    if(nums[l]==0){
                        countZeros--;
                    }
                    l++;
                }

            }
            int length=r-l;
            max_length=max(max_length,length);
            r++;
        }
        if(countZeros==0){
            return n-1;
        }
        return max_length;
    }
};