// Last updated: 8/16/2026, 6:50:56 PM
class Solution {
public:
    int minElement(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            string num=to_string(nums[i]);
            int sum=0;
            for(int j=0;j<num.length();j++){
                sum+=num[j]-'0';
            }
            ans=min(ans,sum);
        }
        return ans;
    }
};