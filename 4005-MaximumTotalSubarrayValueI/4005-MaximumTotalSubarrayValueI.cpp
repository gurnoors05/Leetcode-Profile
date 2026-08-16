// Last updated: 8/16/2026, 6:49:51 PM
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int max_value=INT_MIN;
        int min_value=INT_MAX;
        for(int& num:nums){
            max_value=max(max_value,num);
            min_value=min(min_value,num);
        }
        return 1LL*(max_value-min_value)*k;
    }
};