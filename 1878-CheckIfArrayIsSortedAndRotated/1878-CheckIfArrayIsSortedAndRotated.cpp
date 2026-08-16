// Last updated: 8/16/2026, 6:58:10 PM
class Solution {
public:
    bool check(vector<int>& nums) {
        // int n=nums.size();
        // vector<int> sorted=nums;
        // sort(sorted.begin(),sorted.end());
        // for(int rotations=0;rotations<n;rotations++){
        //     bool isSorted=true;
        //     for(int i=0;i<n;i++){
        //         if(sorted[i]!=nums[(i+rotations)%n]){
        //             isSorted=false;
        //             break;
        //         }
        //     }
        //     if(isSorted){
        //         return true;
        //     }
        // }
        // return false;


        // Other approach, there should be 1 peak only
        int peak=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]>nums[(i+1)%n]){
                peak++;
            }
        }
        return peak<=1;
    }
};