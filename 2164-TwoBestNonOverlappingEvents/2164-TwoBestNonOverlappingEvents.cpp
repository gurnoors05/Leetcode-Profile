// Last updated: 8/16/2026, 6:56:29 PM
class Solution {
public:
    int dp[100001][3];
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int n=events.size();
        memset(dp,-1,sizeof(dp));
        return solve(events,0,2);
    }
    int solve(vector<vector<int>> &events,int i,int k){
        if(k==0 || i>=events.size()){
            return 0;
        }
        if(dp[i][k]!=-1){
            return dp[i][k];
        }
        int skip=solve(events,i+1,k);
        int nextTake=findNext(events,i+1,events[i][1]);
        int take=events[i][2]+solve(events,nextTake,k-1);
        return dp[i][k]=max(take,skip);
    }
    int findNext(vector<vector<int>> &events,int left,int target){
        int right=events.size();
        while(left<right){
            int mid=left+(right-left)/2;
            if(events[mid][0]<=target){
                left=mid+1;
            }
            else{
                right=mid;
            }

        }
        return left;
    }
};