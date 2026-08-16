// Last updated: 8/16/2026, 6:54:30 PM
class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> leftDecreasing(n,1);
        vector<int> rightIncreasing(n,1);
        for(int i=1;i<n;i++){
            if(nums[i-1]>=nums[i]){
                leftDecreasing[i]=leftDecreasing[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i+1]>=nums[i]){
                rightIncreasing[i]=1+rightIncreasing[i+1];
            }
        }
        vector<int> ans;
        for(int i=k;i<n-k;i++){
            if(leftDecreasing[i-1]>=k && rightIncreasing[i+1]>=k){
                ans.push_back(i);
            }
        }
        return ans;

    }
};