// Last updated: 8/16/2026, 6:52:21 PM
class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum=nums[0];
        unordered_set<int> seen(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1){
                sum+=nums[i];
            }
            else{
                break;
            }
        }
        while(seen.count(sum)){
            sum++;
        }
        return sum;
    }
};