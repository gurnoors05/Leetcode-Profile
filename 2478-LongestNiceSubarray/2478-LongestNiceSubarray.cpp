// Last updated: 8/16/2026, 6:54:44 PM
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int l=0;
        int r=0;
        int n=nums.size();
        int mask=0;
        int max_length=INT_MIN;
        while(r<n){
            while((mask & nums[r])!=0){
                mask= mask^ nums[l];
                l++;
            }
            int length=r-l+1;
            max_length=max(max_length,length);
            mask=mask | nums[r];
            r++;
        }
        return max_length;
    }
};