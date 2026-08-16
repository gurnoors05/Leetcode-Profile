// Last updated: 8/16/2026, 6:54:21 PM
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i] = nums[i]*2;
                nums[i+1] = 0;
            }
        }
        int index=0;
        vector<int> result(nums.size(),0);
        for(int num:nums){
            if(num!=0){
                result[index++]=num;
            }
        }
        return result;
    }
};