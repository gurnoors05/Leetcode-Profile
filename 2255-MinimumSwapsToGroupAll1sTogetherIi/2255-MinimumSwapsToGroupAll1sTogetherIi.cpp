// Last updated: 8/16/2026, 6:55:47 PM
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int totalOnes=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                totalOnes++;
            }
        }
        vector<int> doubleNums(2*n);
        for(int i=0;i<2*n;i++){
            doubleNums[i]=nums[i%n];
        }
        int maxTogether=0;
        int l=0;
        int r=0;
        int countOnes=0;
        while(r<2*n){
            if(doubleNums[r]==1){
                countOnes++;
            }
            if((r-l+1)>totalOnes){
                if(doubleNums[l]==1){
                    countOnes--;
                }
                l++;
            }
            maxTogether=max(maxTogether,countOnes);
            r++;
        }
        return totalOnes-maxTogether;
    }
};