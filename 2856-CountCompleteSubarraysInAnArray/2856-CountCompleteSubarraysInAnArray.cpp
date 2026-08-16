// Last updated: 8/16/2026, 6:53:11 PM
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int,int> freq;
        unordered_map<int,int> freq2;

        int n=nums.size();
        int l=0;
        int r=0;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        int size=freq.size();
        int subarrays=0;
        while(r<n){
            freq2[nums[r]]++;
            while(freq2.size()==size){
                subarrays+=n-r;
                freq2[nums[l]]--;
                if(freq2[nums[l]]==0){
                    freq2.erase(nums[l]);
                }
                l++;
            }
            r++;
        }
        return subarrays;

    }
};