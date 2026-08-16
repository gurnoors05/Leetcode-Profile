// Last updated: 8/16/2026, 6:53:46 PM
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            string temp=to_string(nums[i]);
            for(char s:temp){
                ans.push_back(s-'0');
            }
        }
        return ans;
    }
};