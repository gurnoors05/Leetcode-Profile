// Last updated: 8/16/2026, 6:55:08 PM
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long r=0;
        long long l=0;
        long long n=nums.size();
        long long score=1;
        long long subarrays=0;
        long long sum=0;
        while(r<n){
            sum+=nums[r];
            score = sum * (r-l+1);
            while(score>=k){
                sum-=nums[l];
                score=sum*(r-l);
                l++;
            }
            subarrays+=r-l+1;
            r++;
        }
        return subarrays;
    }
};