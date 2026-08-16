// Last updated: 8/16/2026, 6:49:49 PM
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x=0;
        int n=nums.size();
        bool hasNonZero=false;
        for(int i=0;i<nums.size();i++){
            x^=nums[i];
            if(nums[i]!=0){
                hasNonZero=true;
            }
        }
        if(x!=0){
            return n;
        }
        if(hasNonZero){
            return n-1;
        }
        return 0;
    }
};