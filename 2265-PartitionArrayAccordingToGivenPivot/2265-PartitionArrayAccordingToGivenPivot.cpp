// Last updated: 8/16/2026, 6:55:39 PM
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        int lessThan=0;
        int equalTo=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot){
                lessThan++;
            }
            else if(nums[i]==pivot){
                equalTo++;
            }
        }
        int i=0; // less than elements will start from here
        int j=lessThan; // equal elements will start from this index
        int k=lessThan+equalTo; // greater than elements 
        vector<int> ans(n);
        for(auto& num:nums){
            if(num<pivot){
                ans[i]=num;
                i++;
            }
            else if(num==pivot){
                ans[j]=num;
                j++;
            }
            else{
                ans[k]=num;
                k++;
            }
        }
        return ans;
    }
};