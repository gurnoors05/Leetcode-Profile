// Last updated: 8/16/2026, 6:50:51 PM
class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        bool isNotZero=true;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                isNotZero=false;
                break;
            }
        }
        if(isNotZero==true){
            return 0;
        }
        int l=0;
        int r=queries.size()-1;
        int result=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(checkZero(nums,queries,mid)){
                result=mid+1;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return result;
    }
    bool checkZero(vector<int>& nums, vector<vector<int>>& queries,int mid){
        vector<int> difference(nums.size(),0);
        for(int i=0;i<=mid;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int val=queries[i][2];
            difference[l]+=val;
            if(r+1<nums.size()){
                difference[r+1]-=val;
            }
        }
        for(int i=1;i<nums.size();i++){
            difference[i]+=difference[i-1];
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>difference[i]){
                return false;
            }
        }
        return true;
    }
};