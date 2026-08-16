// Last updated: 8/16/2026, 6:53:04 PM
class Solution {
public:
    bool isGood(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        if(nums.size()!=maxi+1){
            return false;
        }
        int count=0;
        unordered_set<int> st;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]!=i+1){
                return false;
            }
        }
        return true;
    }
};