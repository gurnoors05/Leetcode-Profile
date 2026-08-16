// Last updated: 8/16/2026, 6:56:43 PM
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        vector<int> freq(101,0);
        for(auto& num:nums){
            freq[num]++;
        }
        int count=0;
        for(int i=1;i<=101;i++){
            if(i+k<=100){
                count+=freq[i]*freq[i+k];
            }
        }
        return count;
    }
};