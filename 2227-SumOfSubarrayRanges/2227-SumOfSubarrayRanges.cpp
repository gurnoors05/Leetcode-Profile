// Last updated: 8/16/2026, 6:56:04 PM
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            int maxi=nums[i];
            int mini=nums[i];
            for(int j=i+1;j<n;j++){
                maxi=max(maxi,nums[j]);
                mini=min(mini,nums[j]);
                sum+=(maxi-mini);
            }
        }
        return sum;
    }
};