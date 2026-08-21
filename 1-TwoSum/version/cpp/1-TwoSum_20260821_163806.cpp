// Last updated: 8/21/2026, 4:38:06 PM
1class Solution {
2public:
3    vector<int> twoSum(vector<int>& nums, int target) {
4        unordered_map<int,int> mp;
5        for(int i=0;i<nums.size();i++){
6            int remaining=target-nums[i];
7            if(mp.find(remaining)!=mp.end()){
8                return {mp[remaining],i};
9            }
10            mp[nums[i]]=i;
11        }
12        return {};
13    }
14};