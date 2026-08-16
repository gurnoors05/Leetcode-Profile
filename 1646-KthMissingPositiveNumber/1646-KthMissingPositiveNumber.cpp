// Last updated: 8/16/2026, 7:00:18 PM
class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            int missingElements=nums[mid]-(mid+1);
            if(missingElements>=k){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return r+k+1;
    }
};