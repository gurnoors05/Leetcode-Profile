// Last updated: 8/16/2026, 6:50:53 PM
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int l;
        int r;
        vector<int> difference(n+1,0);
        for(auto& q: queries){
            l=q[0];
            r=q[1];
            difference[l]+=1;
            difference[r+1]-=1;

        }
        for(int i=1;i<n;i++){
            difference[i]+=difference[i-1];
        }
        for(int i=0;i<n;i++){
            if(nums[i]>difference[i]){
                return false;
            }
        }
        return true;
    }
};