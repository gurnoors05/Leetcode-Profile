// Last updated: 8/16/2026, 6:54:25 PM
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        return solve(nums,minK,maxK);
    }
    long long solve(vector<int>& nums,int minK,int maxK){
        int min_position=-1;
        int max_position = -1;
        int culprit_Idx=-1;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<minK || nums[i]>maxK){
                culprit_Idx=i;
            }
            if(nums[i]==minK){
                min_position=i;
            }
            if(nums[i]==maxK){
                max_position=i;
            }
            int temp=min(min_position,max_position)-culprit_Idx;
            ans+= temp<0 ? 0: temp;
        }
        return ans;
    }
};