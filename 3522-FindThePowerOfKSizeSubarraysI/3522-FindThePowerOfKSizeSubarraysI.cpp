// Last updated: 8/16/2026, 6:51:11 PM
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans(n-k+1,-1);
        int l=0;
        int r=0;
        int consecutive=0;
        int i=0;
        while(r<n){
            
            if(r>0 && nums[r]==nums[r-1]+1){
                consecutive++;
            }
            if ((r - l + 1) > k) {
                if (l + 1 <= r && nums[l + 1] == nums[l] + 1) {
                    consecutive--;
                }
                l++;
            }

            if ((r - l + 1) == k) {
                if (consecutive == k - 1) { // FIX: should be k-1
                    ans[i] = nums[r];
                }
                i++;
            }
            r++;
        }
        return ans;
    }
};