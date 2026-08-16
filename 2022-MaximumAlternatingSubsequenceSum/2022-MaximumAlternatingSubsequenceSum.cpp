// Last updated: 8/16/2026, 6:57:16 PM
class Solution {
public:
    // long long t[100001][2];
    long long maxAlternatingSum(vector<int>& nums) {
        

        //Bottom-up
        int n=nums.size();
        vector<vector<long long>> t(n+1, vector<long long>(2,0));
        for(int i=1;i<n+1;i++){
            t[i][0]=max(t[i-1][1]-nums[i-1],t[i-1][0]); //makes even length array, 0 represents even and 1 represents odd
            t[i][1]=max(t[i-1][0]+nums[i-1], t[i-1][1]); //makes odd length array, 0 represents even and 1 represents odd
        }
        return max(t[n][0],t[n][1]);

        // memset(t, -1, sizeof(t));
        // return solve(nums,0,true);
    }
    // long long solve(vector<int>& nums,int i,bool isEven){
    //     int n=nums.size();
    //     if(i>=n){
    //         return 0;
    //     }
    //     if(t[i][isEven]!=-1){
    //         return t[i][isEven];
    //     }
    //     long long skip=solve(nums,i+1, isEven);
    //     long long val=nums[i];
    //     if(isEven==false){
    //         val = -val;
    //     }
    //     long long take=solve(nums,i+1,!isEven)+val;
    //     return t[i][isEven]=max(take,skip);
    // }
};