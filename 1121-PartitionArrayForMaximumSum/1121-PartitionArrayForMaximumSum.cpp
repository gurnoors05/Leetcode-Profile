// Last updated: 8/16/2026, 7:05:16 PM
class Solution {
public:
    int dp[501];
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof(dp));
        return  solve(arr,k,0);
    }
    int solve(vector<int>& arr, int k,int i){
        if(i>=arr.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int maxi=INT_MIN;
        int result=0;
        for(int j=i;j<arr.size() && j-i+1<=k;j++){
            maxi=max(maxi,arr[j]);
            int total=maxi*(j-i+1)+solve(arr,k,j+1);
            result=max(result,total);
        }
        return dp[i]=result;
    }
};