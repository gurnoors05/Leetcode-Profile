// Last updated: 8/16/2026, 6:56:13 PM
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        return solve(nums,k);
    }
    vector<int> solve(vector<int>& nums,int k){
        int left=0;
        int right=2*k;
        int n=nums.size();

        vector<int> ans(n,-1);
        if(n<2*k+1){
            return ans;
        }
        int i=k;
        long long sum=0;
        for(int j=left;j<=right;j++){
            sum+=nums[j];
        }
        int windowSize=(right-left+1);
        int avg=sum/windowSize;
        ans[k]=avg;
       i++;
        right++;
        while(right<n){
            int out=nums[left];
            int in=nums[right];
            sum-=out;
            sum+=in;
            ans[i]=sum/windowSize;
            left++;
            right++;
            i++;
        }
        return ans;
    }
};