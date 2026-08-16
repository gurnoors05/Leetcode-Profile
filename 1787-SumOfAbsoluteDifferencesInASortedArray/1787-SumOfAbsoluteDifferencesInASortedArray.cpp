// Last updated: 8/16/2026, 6:58:57 PM
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=nums[i]+prefix[i-1];
        }
        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=nums[i]+suffix[i+1];
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int leftSum=(i>0)?prefix[i-1]:0;
            int rightSum=(i<n-1)?suffix[i+1]:0;
            int leftPart=(nums[i]*i)-leftSum;
            int rightPart=rightSum-(nums[i]*(n-i-1));
            ans[i]=leftPart+rightPart;
        }
        return ans;
    }
};