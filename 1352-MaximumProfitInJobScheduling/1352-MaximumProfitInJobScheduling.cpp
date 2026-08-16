// Last updated: 8/16/2026, 7:03:14 PM
class Solution {
public:
    int n;
    int dp[50001];
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n=startTime.size();
        vector<vector<int>> array(n,vector<int>(3,0));
        for(int i=0;i<n;i++){
            array[i][0]=startTime[i];
            array[i][1]=endTime[i];
            array[i][2]=profit[i];
        }
        sort(begin(array),end(array), [&](auto& array1,auto& array2){
            return array1[0]<array2[0];
        });
        memset(dp,-1,sizeof(dp));
        return solve(array,0);
    }
    int solve(vector<vector<int>>& array,int i){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int nextIndex=findNextIndex(array,i+1,array[i][1]);
        int take=array[i][2]+solve(array,nextIndex);
        int not_take=solve(array,i+1);
        return dp[i]=max(take,not_take);
    }
    int findNextIndex(vector<vector<int>>& array,int l,int endJobTime){
        int r=n-1;
        int result=n+1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(array[mid][0]>=endJobTime){
                result=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return result;
    }
};