// Last updated: 8/16/2026, 6:54:18 PM
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> st;
        int l=0;
        int r=0;
        int n=nums.size();
        long long currSum=0;
        long long result=0;
        while(r<n){
            while(st.count(nums[r])){
                currSum-=nums[l];
                st.erase(nums[l]);
                l++;
            }
            currSum+=nums[r];
            st.insert(nums[r]);
            if((r-l+1)==k){
                result=max(currSum,result);
                currSum-=nums[l];
                st.erase(nums[l]);
                l++;
            }
            
            r++;

        }
        return result;
    }
};