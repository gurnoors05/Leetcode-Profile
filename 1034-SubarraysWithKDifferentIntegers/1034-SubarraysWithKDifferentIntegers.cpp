// Last updated: 8/16/2026, 7:06:05 PM
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
    int solve(vector<int>& nums,int k){
        int n=nums.size();
        int l=0;
        int r=0;
        unordered_map<int,int> mp;
        int noOfSub=0;
        while(r<n){
            mp[nums[r]]++;
            if(mp.size()>k){
                while(mp.size()>k){
                    mp[nums[l]]--;
                    if(mp[nums[l]]==0){
                        mp.erase(nums[l]);
                    }
                    l++;
                }
            }
            noOfSub+=(r-l+1);
            r++;
        }
        return noOfSub;
    }
};