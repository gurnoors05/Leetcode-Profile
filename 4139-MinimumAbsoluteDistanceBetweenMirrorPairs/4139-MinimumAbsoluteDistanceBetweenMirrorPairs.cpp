// Last updated: 8/16/2026, 6:49:33 PM
class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i])!=mp.end()){
                ans=min(ans,i-mp[nums[i]]);
            }
            mp[reverse(nums[i])]=i;
        }
        return ans==INT_MAX?-1:ans;
    }
    int reverse(int num){
        int rev=0;
        while(num>0){
            int digit=num%10;
            rev=rev*10+digit;
            num/=10;
        }
        return rev;
    }
};