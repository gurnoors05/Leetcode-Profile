// Last updated: 8/16/2026, 6:52:34 PM
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        return solve(nums,k);
    }
    long long solve(vector<int>& nums,int k){
        int l=0;
        int r=0;
        int n=nums.size();
        int maxi=*max_element(begin(nums),end(nums));
        long long count=0;
        long long result=0;
        while(r<n){
            if(nums[r]==maxi){
                count++;

            }
            if(count>=k){
                while(count>=k){
                    result+=n-r;
                    if(nums[l]==maxi){
                        count--;
                    }
                    l++;
                }
            }
            r++;
        }
        return result;
    }
};