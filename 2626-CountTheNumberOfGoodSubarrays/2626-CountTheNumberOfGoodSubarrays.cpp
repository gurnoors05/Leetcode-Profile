// Last updated: 8/16/2026, 6:53:50 PM
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int n=nums.size();
        unordered_map<int,int> mp;
        long long pairs=0;
        long long result=0;
        while(r<n){
            if(mp.count(nums[r])){
                pairs+=mp[nums[r]];
            }
            mp[nums[r]]++;
            if(pairs>=k){
                while(pairs>=k){
                    result+=n-r;
                    mp[nums[l]]--;
                    pairs-=mp[nums[l]];
                    l++;
                }
            }
            r++;
        }
        return result;
    }
};