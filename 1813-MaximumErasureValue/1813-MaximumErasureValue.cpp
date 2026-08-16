// Last updated: 8/16/2026, 6:58:33 PM
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> st;
        int l=0;
        int r=0;
        int n=nums.size();
        int sum=0;
        int maxSum=0;
        while(r<n){
            if(!st.count(nums[r])){
                sum+=nums[r];
                maxSum=max(maxSum,sum);
                st.insert(nums[r]);
                r++;
            }
            else{
                while(l<n && st.count(nums[r])){
                    sum-=nums[l];
                    st.erase(nums[l]);
                    l++;
                }
            }
        }
        return maxSum;
    }
};