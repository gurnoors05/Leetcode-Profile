// Last updated: 8/16/2026, 6:57:40 PM
class Solution {
public:
    // using sorting and binary search
    // int maxFrequency(vector<int>& nums, int k) {
    //     sort(nums.begin(),nums.end());
    //     int n=nums.size();
    //      vector<long> prefixSum(n);
    //     prefixSum[0] = nums[0];
    //     for(int i = 1; i < n; i++) {
    //         prefixSum[i] = prefixSum[i-1] + nums[i];
    //     }
    //     int max_freq=INT_MIN;
    //     for(int i=0;i<n;i++){
    //         int freq=binarySearch(i,nums,k,prefixSum);
    //         max_freq=max(freq,max_freq);
    //     }
    //     return max_freq;
    // }
    // int binarySearch(int target_idx, vector<int>& nums,int k,vector<long>& prevSum){
    //     int l=0;
    //     int r=target_idx;
    //     int result=target_idx;
    //     while(l<=r){
    //         int mid=l+(r-l)/2;
    //         long count=target_idx-mid+1;
    //         long window_size=count*nums[target_idx];
    //         long original_sum=prevSum[target_idx]-prevSum[mid]+nums[mid];
    //         int op=window_size-original_sum;
    //         if(op>k){
    //             l=mid+1;
    //         }
    //         else{
    //             result=mid;
    //             r=mid-1;
    //         }

    //     }
    //     return target_idx-result+1;

    // }

    //Using Sliding Window
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
         vector<long> prefixSum(n);
        prefixSum[0] = nums[0];
        for(int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }
        int max_freq=1;
        int l=0;
        int r=0;
        while(r<n){
            long long count=r-l+1;
            long long windowSum= count*nums[r];
            long long original_sum = prefixSum[r]-(l > 0 ? prefixSum[l - 1] : 0);
            long long op = windowSum-original_sum;
            while(op>k){
                l++;
                count=r-l+1;
                windowSum= count*nums[r];
                original_sum = prefixSum[r]-(l > 0 ? prefixSum[l - 1] : 0);
                op = windowSum-original_sum;
            }
            max_freq=max(max_freq,r-l+1);
            r++;
        }
        return max_freq;

    }
};
