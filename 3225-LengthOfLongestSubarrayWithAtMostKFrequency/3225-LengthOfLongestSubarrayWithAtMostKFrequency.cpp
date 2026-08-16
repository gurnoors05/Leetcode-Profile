// Last updated: 8/16/2026, 6:52:27 PM
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int l=0;
        int r=0;
        int n=nums.size();
        int result=INT_MIN;
        while(r<n){
            mp[nums[r]]++;
            if(mp[nums[r]]>k){
                while(mp[nums[r]]>k){
                    mp[nums[l]]--;
                    if(mp[nums[l]]==0){
                        mp.erase(nums[l]);
                    }
                    l++;
                }
            }
            result=max(result,r-l+1);
            r++;
        }
        return result;
    }
};