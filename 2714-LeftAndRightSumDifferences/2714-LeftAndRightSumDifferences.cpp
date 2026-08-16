// Last updated: 8/16/2026, 6:53:30 PM
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int> leftSum(n);
        vector<int> rightSum(n);
        int sum1=0;
        int sum2=0;
        for(int i=0;i<n;i++){
            leftSum[i]=sum1;
            sum1+=nums[i];
        }
        for(int i=n-1;i>=0;i--){
            rightSum[i]=sum2;
            sum2+=nums[i];
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=abs(leftSum[i]-rightSum[i]);
        }
        return ans;
    }
};