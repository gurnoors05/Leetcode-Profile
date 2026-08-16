// Last updated: 8/16/2026, 7:02:45 PM
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left=1;
        int right=*max_element(nums.begin(),nums.end());
        int ans=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(check(mid,nums,threshold)){
                right=mid-1;
                ans=mid;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
    bool check(int mid,vector<int>& nums, int threshold){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=(nums[i]+mid-1)/mid;
            if(sum>threshold){
                return false;
            }
        }
        return true;
    }
};