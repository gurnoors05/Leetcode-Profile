// Last updated: 8/16/2026, 6:53:34 PM
class Solution {
public:
    int count=0;
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        solve(nums,k,mp,0);
        return count-1;
    }
    void solve(vector<int>& nums, int k,unordered_map<int,int> &mp,int i){
        if(i==nums.size()){
            count++;
            return;
        }
        solve(nums,k,mp,i+1);
        if(!mp[nums[i]-k] && !mp[nums[i]+k]){
            mp[nums[i]]++;
            solve(nums, k, mp,i+1);
            mp[nums[i]]--;
        }

    }
};